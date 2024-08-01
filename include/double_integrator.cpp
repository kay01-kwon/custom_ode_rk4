#include "double_integrator.h"

DoubleIntegrator::DoubleIntegrator()
:s_(s_.setZero()),
dsdt_(dsdt_.setZero()),
t_(0),
dt_(0.01)
{
    A << 0, 1,
        0, 0;
    B << 0, 1;
}

void DoubleIntegrator::integrate()
{

    rk4_solver.do_step(
        [this]
        (const mat21_t& s, mat21_t& dsdt, const double& t)
        {
            this->DoubleIntegrator::system_dynamics(s, dsdt, t, u_);
        },
        s_, t_, dt_
    );

    t_ += dt_;
}

void DoubleIntegrator::set_input(const double &u)
{
    u_ = u;
}

void DoubleIntegrator::get_state(mat21_t &state) const
{
    state = s_;
}

void DoubleIntegrator::get_time(double &time) const
{
    time = t_;
}


void DoubleIntegrator::system_dynamics(const mat21_t &s, 
mat21_t &dsdt, 
const double &t,
const double &u)
{
    dsdt = A*s + B*u;
}

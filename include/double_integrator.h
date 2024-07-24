#ifndef DOUBLE_INTEGRATOR_H_
#define DOUBLE_INTEGRATOR_H_
#include "type_define.h"
#include "ode_rk4_custom.h"

class DoubleIntegrator{

    public:

        DoubleIntegrator();
        
        void integrate();

        void set_input(const double &u);

        void get_state(mat21_t& state) const;

        void get_time(double& time) const;

        ~DoubleIntegrator() = default;


        void system_dynamics(const mat21_t &s_, mat21_t &dsdt_, const double &t);

    private:

        mat21_t s_, dsdt_;
        double u_;

        double t_;
        double dt_;

        mat22_t A;
        mat21_t B;

        OdeRK4Custom<mat21_t> rk4_solver;


};


#endif
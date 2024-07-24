#include "double_integrator.h"


int main(int argc, char** argv)
{
    DoubleIntegrator double_integrator_obj;

    double u = 1;
    double time = 0;
    mat21_t state;

    state.setZero();

    for(size_t i = 0; i < 100; i ++)
    {
        double_integrator_obj.set_input(u);

        double_integrator_obj.integrate();

        double_integrator_obj.get_state(state);

        double_integrator_obj.get_time(time);


        cout << "Time: ";
        cout << time << endl;

        cout << "State variables: ";

        for(size_t i = 0; i < state.size(); i++)
            cout << state(i) << " ";
        cout << endl;

        cout << endl;

    }

    return EXIT_SUCCESS;
}
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <nombre_del_archivo>" << std::endl;
        return 1; // Terminar el programa con un código de error
    }

    // Obtener el nombre del archivo desde el argumento de la línea de comandos
    const std::string fileName = argv[1];

    std::ifstream file(fileName);


    int *bt;
    int *wt;
    int *rt;

    int proccess;
    file>>proccess;

    bt = new int[proccess]; // Burst time
    wt = new int[proccess]; // Waiting time
    rt = new int[proccess]; // Remaining time

    wt[0] = 0; // Waiting time for first process is 0


    int total_wt = 0;
    int total_rt = 0;

    for(int i=0; i<proccess; i++) {
        file>>bt[i];

        if(i>0) {
            wt[i] = wt[i-1] + bt[i-1];
        }

        rt[i] = bt[i] + wt[i];
    
        total_wt += wt[i];
        total_rt += rt[i];
    }


    std::cout << std::setw(2) << "Proceso"
            << std::setw(20) << "Tiempo de rafaga"
            << std::setw(20) << "Tiempo de espera"
            << std::setw(23) << "Tiempo de respuesta" << std::endl;

    // Print the table content
    for (int i = 0; i < proccess; i++) {
        std::cout << std::setw(2) << std::to_string(i + 1)
                << std::setw(25) << bt[i]
                << std::setw(20) << wt[i]
                << std::setw(23) << rt[i] << std::endl;
    }

    cout<<"Tiempo medio de espera: "<<total_wt * 1.0 / proccess<<endl;
    cout<<"Tiempo medio de respuesta: "<<total_rt * 1.0 / proccess<<endl;

    return 0;
}
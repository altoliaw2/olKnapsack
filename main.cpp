#include <algorithm>
#include <iostream>

const int N = 4, W = 100;
int cost[N]={400, 150, 150, 120};
int weight[N]={85, 30, 50, 20};
int c[N + 1][W + 1]={};

void fn_OLKnapsack(const int ci_IN, const int ci_TWei,
              int* ip_Cost, int* ip_Weight, int** ia_MCost);

int main(){
    const int ci_IN = 4; // COM: Number of Items
    const int ci_TWei = 100;// COM: Remainder from the bag
    int i_Cost[ci_IN]={400, 150, 150, 120};
    int i_Weight[ci_IN]={85, 30, 50, 20};

    int** ia_MCost = new int*[(ci_IN+ 1)];
    for(int i_Ct = 0; i_Ct <= ci_IN; i_Ct++){
        ia_MCost[i_Ct] = new int[(ci_TWei + 1)]{};
    }

    fn_OLKnapsack(ci_IN, ci_TWei, i_Cost, i_Weight, ia_MCost);

    for(int i_Ct = 0; i_Ct <= ci_IN; i_Ct++){
        delete [] ia_MCost[i_Ct];
    }
    delete [] ia_MCost;
    return 0;
}

void fn_OLKnapsack(const int ci_IN, const int ci_TWei,
              int* ip_Cost, int* ip_Weight, int** ia_MCost){

    //COM: Loops for items
    for (int i_Ct1 = 0; i_Ct1 < ci_IN; i_Ct1++){
        //COM: Loops for weights
        for (int i_Ct2 = 0; i_Ct2 <= ci_TWei; i_Ct2++){
            //COM: If the weight of the bag < weight of the item
            if (i_Ct2 - ip_Weight[i_Ct1] < 0){
                ia_MCost[i_Ct1+1][i_Ct2] = ia_MCost[i_Ct1][i_Ct2];
            }
            else{
                ia_MCost[i_Ct1+1][i_Ct2] = std::max(
                    ia_MCost[i_Ct1][i_Ct2],
                    (ia_MCost[i_Ct1][i_Ct2 - ip_Weight[i_Ct1]] +
                    ip_Cost[i_Ct1])
                );
            }
        }
    }
    std::cout << "Max Value is: " << ia_MCost[ci_IN][ci_TWei];
}

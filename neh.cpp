#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
#include <fstream>

using namespace std;


class Zadanie{
    public:
    int numer;
    //int m1,m2,m3;
    vector<int>maszyny;

    Zadanie(int d){

        numer= d;
    }

};

vector<Zadanie>zadania;
vector<Zadanie>uszeregowanie;
vector<Zadanie>temp;


int zwroc_max(){
    
   int  sum=0; 
   int  max=0;
   int indeks_max= 0;

    for(int i=0; i<zadania.size(); i++){
        for(int j=0; j<zadania[i].maszyny.size(); j++){
        sum += zadania[i].maszyny[j];
        }
    
        if(sum > max){
            max= sum;
            indeks_max= i;
        }
    }
    return indeks_max;
}




int main(){

ifstream Data ("data.txt");
int N, M, zad;
Data >> N;
Data >> M;
for(int i=0;i<N;i++){
Zadanie a(i);
  for (int j=0;j<M;j++){  
  Data >> zad;
  a.maszyny.push_back(zad);
  }
  zadania.push_back(a);
}
//Zadanie  a(1,1,3,1); // 5
//Zadanie  b(4,1,2,2); // 7
//Zadanie  c(3,4,3,3); // 10
//Zadanie  d(2,4,1,4); // 7


//zadania.push_back(a);
//zadania.push_back(b);
//zadania.push_back(c);
//zadania.push_back(d);


//obliczamy łączny czas

// for(int i =0; i<zadania.size(); i++){
//     cout<<zadania[i].m1<<endl;
// }
int indeks_temp;
int zad_m1=0, zad_m2=0, zad_m3=0, cmax;
int liczba_zadan = zadania.size();
//int zad_zero=0;

//zmienic na rozmair 
for(int j=0; j<liczba_zadan; j++){

    int indeks_max= zwroc_max();
    uszeregowanie.push_back(zadania[indeks_max]);
    zadania.erase(zadania.begin()+indeks_max);

    for(int p=0; p<uszeregowanie.size(); p++){
        temp.push_back(uszeregowanie[p]);
    }

    indeks_temp = 0;
    cmax=INT_MAX;
    for(int i=0; i<uszeregowanie.size(); i++){
        if(i>=2) {
        indeks_temp++;
        }

        cout<<endl;
        cout<<"Przed swapem: ";
        for(int o= 0; o<temp.size(); o++){
            cout<<temp[o].numer;
        }
        //for(int v= 0; v<uszeregowanie.size(); v++){
        swap(temp[temp.size()-1-indeks_temp], temp[temp.size()-1-i]);
               
        //}
        cout<<endl;
        cout<<"Po swapie: ";
        for(int o= 0; o<temp.size(); o++){
            cout<<temp[o].numer;
        }

        zad_m1=0, zad_m2=0, zad_m3=0;
        int zad_maszyny[temp[0].maszyny.size()-1];
        //cmax=INT_MAX;
        cout <<endl;
        for(int a=0;a<temp.size();a++){
            for(int m=0;m<temp[a].maszyny.size();m++){
            if(a==0){
                if(m==0)zad_maszyny[0]=temp[a].maszyny[m];
                else{
                    zad_maszyny[m]=temp[a].maszyny[m]+zad_maszyny[m-1];
                }
                //cout<<"zad_m1 = " << zad_m1 << endl;
                //zad_m2=temp[a].m2+zad_m1;
                //cout<<"zad_m2 = " << zad_m2 << endl;
                //zad_m3=temp[a].m3+zad_m2;
                //cout<<"zad_m3 = " << zad_m3 << endl;
            }
            else{
                if(m==0)zad_maszyny[0] = max(0,zad_maszyny[0]) + temp[a].maszyny[m];
                else{
                    zad_maszyny[m] = max(zad_maszyny[m-1],zad_maszyny[m]) + temp[a].maszyny[m];
                }
                //cout<<"zad_m1 = " << zad_m1 << endl;
                //zad_m2 = max(zad_m1,zad_m2) + temp[a].m2;
                //cout<<"zad_m2 = " << zad_m2 << endl;
                //zad_m3 = max(zad_m2, zad_m3) + temp[a].m3;
                //cout<<"zad_m3 = " << zad_m3 << endl;
                }
            }

        }
        //cmax=zad_m3;
        cout<<endl;
        cout<< "Cmax: "<< zad_maszyny[temp[0].maszyny.size()-1] << endl;
        if(zad_maszyny[temp[0].maszyny.size()-1]<cmax){
            cmax=zad_maszyny[temp[0].maszyny.size()-1];
            uszeregowanie.clear();
            for(int b=0;b<temp.size();b++){
                uszeregowanie.push_back(temp[b]);
            }
        }

    }


    temp.clear();
    cout<<"Najlepszy cmax = " << cmax << endl;
    cout<<"Najlepsze uszeregowanie: ";
    for(int o= 0; o<uszeregowanie.size(); o++){
        cout<<uszeregowanie[o].numer;
        }
    cout<<endl;

}

return 0;
}
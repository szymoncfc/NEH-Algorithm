#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>

using namespace std;


class Zadanie{
    public:
    int numer;
    int m1,m2,m3;

    Zadanie(int a, int b, int c ,int d){
        m1= a;
        m2= b;
        m3= c; 
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
        sum= zadania[i].m1 + zadania[i].m2 + zadania[i].m3;
        
    
        if(sum > max){
            max= sum;
            indeks_max= i;
        }
    }
    return indeks_max;
}




int main(){

Zadanie  a(1,1,3,1); // 5
Zadanie  b(4,1,2,2); // 7
Zadanie  c(3,4,3,3); // 10
Zadanie  d(2,4,1,4); // 7


zadania.push_back(a);
zadania.push_back(b);
zadania.push_back(c);
zadania.push_back(d);


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
        //cmax=INT_MAX;
        cout <<endl;
        for(int a=0;a<temp.size();a++){
        //for(int m=0;m<3;m++){
            if(a==0){
                zad_m1=temp[a].m1;
                //cout<<"zad_m1 = " << zad_m1 << endl;
                zad_m2=temp[a].m2+zad_m1;
                //cout<<"zad_m2 = " << zad_m2 << endl;
                zad_m3=temp[a].m3+zad_m2;
                //cout<<"zad_m3 = " << zad_m3 << endl;
            }
            else{
                zad_m1 = max(0,zad_m1) + temp[a].m1;
                //cout<<"zad_m1 = " << zad_m1 << endl;
                zad_m2 = max(zad_m1,zad_m2) + temp[a].m2;
                //cout<<"zad_m2 = " << zad_m2 << endl;
                zad_m3 = max(zad_m2, zad_m3) + temp[a].m3;
                //cout<<"zad_m3 = " << zad_m3 << endl;
                }
            //}

        }
        //cmax=zad_m3;
        cout<<endl;
        cout<< "Cmax: "<< zad_m3 << endl;
        if(zad_m3<cmax){
            cmax=zad_m3;
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
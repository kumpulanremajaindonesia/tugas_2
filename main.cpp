#include <iostream>
using namespace std;

#define max 5
int front = 0;
int back = 0;

string dataantrianbank[max];

//isFullarray : cek apakah antrian penuh
bool isFullArray() {
    if(back==max) 
        return true;
    else 
        return false;
}

//isEmptyArray : cek apakah antrian kosong
bool isEmptyArray() {
    if(back==0) 
        return true;
    else 
        return false;
}

//proses enqueue : penambahan data antrian
void enqueueArray(string data) {
    //di cek dlu yah full apa ga
    if(isFullArray()) {
        cout << "Antrian Penuh" << endl;
    }
    else {
        if(isEmptyArray()) {
        dataantrianbank[0] = data;
        back++;
        front++;
        }
        else {
        dataantrianbank[back] = data;
        back++; 
        }
    }
}
//count
int countArray(){
    if(isEmptyArray()) {
        return 0;
    }
    else if(isFullArray()) {
        return max;
    }
    else return back;
    
}

//display
void viewArray() {
    cout << "Data Antrian Bank" << endl;
    if(isEmptyArray()) {
            cout << "Antrian Kosong" << endl; 
    }
    else {
        for(int i = 0; i<max; i++) {
        
        //kalau ruang tidak kosong
            if(dataantrianbank[i] != "") {
                cout << i+1 << ". " << dataantrianbank[i] << endl;
            }
        //kalau ruang tidak kosong
            else {
                cout << i+1 << ". " << "(kosong)" << endl;
            }
        }
    }
    cout << "jumlah data yang antri: " << countArray() << " data." << endl;
    cout << endl << endl;
}

//penghapusan data depan
void dequeueArray() {
    if(isEmptyArray()) {
        cout << "Antrian Kosong" << endl; 
    }
    else {
       for(int i=0; i<back; i++) {
            dataantrianbank[i] = dataantrianbank[i+1];
       }
       back--;
    }
}

//destroy /cleare queue
void destroyArray() {
    if(isEmptyArray()) {
        cout << "Antrian Kosong" << endl; 
    }
    else {
       for(int i=0; i<back; i++) {
            dataantrianbank[i] = "";
       }
       front=0;
       back=0;
    }
}




int main() {

    enqueueArray("Esa");
    viewArray();

    enqueueArray("Ichsan");
    enqueueArray("Fransiska");
    enqueueArray("Elmira");
    enqueueArray("Gilang");
    viewArray();

    enqueueArray("Contoh");
    viewArray();

    dequeueArray();
    viewArray();
    
    dequeueArray();
    viewArray();

    destroyArray();
    viewArray();

    enqueueArray("Otong");
    viewArray();

}
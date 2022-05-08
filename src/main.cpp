#include <iostream>
#include <cmath>
using namespace std;

class persegiPanjang{
    private:
        float xMaks, xMin, yMaks, yMin;
    public:
        persegiPanjang(float titikTengahX, float titikTengahY, float panjang, float lebar);
        bool operator== (persegiPanjang const &)const;
        persegiPanjang operator+ (persegiPanjang const &);
        persegiPanjang operator- (persegiPanjang const &);
        void operator++ ();
        void operator++(int);
        void operator-- ();
        void operator--(int);
        float operator[](int pilihan);
        void output();
        
        
};
    float panjang, lebar, tx, ty;
    void input();
int main(){
    int pilihan;
    const char *index[4] = {"xMin", "xMaks", "yMin", "yMaks"};

    persegiPanjang pp3(0,0,0,0);


    cout << "Masukkan Data Persegi Panjang 1" << endl;
    input();
    persegiPanjang pp1(tx, ty, panjang, lebar);
    cout << "Masukkan Data Persegi Panjang 2" << endl;
    input();
    persegiPanjang pp2(tx, ty, panjang, lebar);

    system("CLS");

    while (1){
        cout << "Silahkan pilih operator yang ingin digunakan" << endl;
        cout << "1. OPERATOR +" << endl << "2. OPERATOR -" << endl << "3. OPERATOR ++" << endl<< "4. OPERATOR --" << endl << "5. OPERATOR []" << endl<< "6. OPERATOR ==" << endl << "7. Exit Program" << endl<< "Pilihan anda : "; cin >> pilihan;
        switch (pilihan){
        case 1:
            {
                system("CLS");
                cout << endl;
                cout << "Mengambil luas gabungan dari 2 persegi panjang" << endl;
                pp3 = pp1 + pp2;
                if (pp1==pp2){
                    pp3.output();
                }
                cin.get();
                system("CLS");
            }
            break;
        case 2:
            {
                system("CLS");
                cout << endl;
                cout << "Mengambil irisan 2 persegi panjang" << endl;
                pp3 = pp1 - pp2;
                if (pp1==pp2){
                    pp3.output();
                }
                cin.get();

            }
            break;
        case 3:
            {
                system("CLS");
                cout << endl;
                cout << "OPERATOR ++ (Menjadikan luas persegi panjang 2 kali lebih besar)" << endl;
                ++pp1;
                cout << "Persegi Panjang 1 setelah diberi Operator ++ : " << endl;
                pp1.output();
                --pp1;
                ++pp2;
                cout << "Persegi Panjang 2 setelah diberi Operator ++ : " << endl;
                pp2.output();
                --pp2;
                cin.get();
            }
            break;
        case 4:
            {
                system("CLS");
                cout << endl;
                cout << "OPERATOR -- (Menjadikan luas persegi panjang 2 kali lebih kecil (1/2 kali semula))" << endl;
                --pp1;
                cout << "Persegi Panjang 1 setelah diberi Operator -- : " << endl;
                pp1.output();
                ++pp1;
                --pp2;
                cout << "Persegi Panjang 2 setelah diberi Operator -- : " << endl;
                pp2.output();
                ++pp2;
                cin.get();
            }
            break;
        case 5:
            {
                system("CLS");
                cout << endl;
                cout << "OPERATOR [] (Perbandingan indeks Pp1 dan Pp2)" << endl;
                for(int pilihan = 1; pilihan < 5; pilihan++){
                    cout << "Nilai " << index[pilihan-1] << " Pp1 : " << pp1[pilihan] << endl;
                    cout << "Nilai " << index[pilihan-1] << " Pp2 : " << pp2[pilihan] << endl;
                    if (pp1[pilihan] > pp2[pilihan]){
                        cout << index[pilihan-1] << " Pp1 lebih besar dari " << index[pilihan-1] << " Pp2" << endl;
                    }else if(pp2[pilihan] > pp1[pilihan]){
                        cout << index[pilihan-1] << " Pp2 lebih besar dari " << index[pilihan-1] << " Pp1" << endl;;
                    }else{
                        cout << "Kedua " << index[pilihan-1] << " sama" << endl;
                    }
                    cout << endl<< endl;
                }
                cin.get();
                system("CLS");
            }
            break;
        case 6:
            {
                system("CLS");
                cout << endl;
                cout << "OPERATOR == (Pembuktian Kedua Persegi panjang saling beririsan/tidak)" << endl;
                if (pp1==pp2){
                    cout << "Kedua persegi panjang beririsan" << endl;
                }else{
                    cout << "Kedua persegi panjang tidak beririsan" << endl;
                }
                cin.get();
                system("CLS");
            }
            break;
        case 7:
            return 0;
        }
    }
}


void persegiPanjang::output(){
    float panjang = this->xMaks - this->xMin; panjang = abs(panjang);
    float lebar   = this->yMaks - this->yMin; lebar   = abs (lebar);
    
    cout << "Titik Tengah X : " << (this->xMaks - this->xMin)/2 + this->xMin; cout << endl;
    cout << "Titik Tengah Y : " << (this->yMaks - this->yMin)/2 + this->yMin; cout << endl;
    cout << "Panjang (Sumbu X) : " << panjang; cout << endl;
    cout << "Lebar (Sumbu Y) : " << lebar; cout << endl;
    cout << "Nilai xMin : " << this->xMin; cout << endl;
    cout << "Nilai xMmaks : " << this->xMaks; cout << endl;
    cout << "Nilai yMin : " << this->yMin; cout << endl;
    cout << "Nilai yMaks : " << this->yMaks; cout << endl;
}

persegiPanjang::persegiPanjang(float titikTengahX, float titikTengahY, float panjang, float lebar){
    this->xMin = titikTengahX - (panjang/2);
    this->yMin = titikTengahY - (lebar/2);
    this->xMaks = titikTengahX + (panjang/2);
    this->yMaks = titikTengahY + (lebar/2);
}

bool persegiPanjang::operator==(persegiPanjang const &baru)const{
    if (this->xMaks > baru.xMin && this->xMin < baru.xMaks && this->yMaks > baru.yMin && this->yMin < baru.yMaks){
        return true;
    }else{
        return false;
    }
}

persegiPanjang persegiPanjang::operator+(persegiPanjang const &baru){
    persegiPanjang temp(0,0,0,0);

    if (*this == baru){
        temp.xMin = min(this-> xMin,baru.xMin);
        temp.yMin = min(this-> yMin,baru.yMin);
        temp.xMaks = max(this-> xMaks,baru.xMaks);
        temp.yMaks = max(this-> yMaks,baru.yMaks);
    }else{
        cout << "Kedua bangun tidak beririsan" << endl;
    }
    return temp;
}

persegiPanjang persegiPanjang::operator-(persegiPanjang const &baru){
    persegiPanjang temp(0,0,0,0);

    if (*this == baru){
        temp.xMin = max(this-> xMin,baru.xMin);
        temp.yMin = max(this-> yMin,baru.yMin);
        temp.xMaks = min(this-> xMaks,baru.xMaks);
        temp.yMaks = min(this-> yMaks,baru.yMaks);
    }else{
        cout << "Kedua bangun tidak beririsan" << endl;
    }
    return temp;
}

void persegiPanjang::operator++(){
    float panjang = 0, lebar = 0, xMidpoint = 0, yMidpoint = 0;

    panjang = this->xMaks - this->xMin; panjang = abs(panjang);
    lebar = this->yMaks - this->yMin; lebar = abs(lebar);
    xMidpoint = this->xMin + panjang/2;
    yMidpoint = this->yMin + lebar/2;

    panjang = panjang * 2;
    lebar = lebar * 2;

    this->xMin = xMidpoint - panjang/2;
    this->yMin = yMidpoint - lebar/2;
    this->xMaks = xMidpoint + panjang/2;
    this->yMaks = yMidpoint + lebar/2;
}

void persegiPanjang::operator--(){
    float panjang = 0, lebar = 0, xMidpoint = 0, yMidpoint = 0;

    panjang = this->xMaks - this->xMin; panjang = abs(panjang);
    lebar = this->yMaks - this->yMin; lebar = abs(lebar);
    xMidpoint = this->xMin + panjang/2;
    yMidpoint = this->yMin + lebar/2;

    panjang = panjang / 2;
    lebar = lebar / 2;

    this->xMin = xMidpoint - panjang/2;
    this->yMin = yMidpoint - lebar/2;
    this->xMaks = xMidpoint + panjang/2;
    this->yMaks = yMidpoint + lebar/2;
}
void persegiPanjang::operator++(int){}
void persegiPanjang::operator--(int){}

float persegiPanjang::operator[](int pilihan){
    switch (pilihan){
    case 1:
        return this->xMin;
        break;
    case 2:
        return this->xMaks;
        break;
    case 3:
        return this->yMin;
        break;
    case 4:
        return this->yMaks;
        break;
    }
    return 0;
}

void input(){
    cout << "Panjang (Sumbu X) : "; cin >> panjang; cout << endl;
    cout << "Lebar (Sumbu Y) : "; cin >> lebar; cout << endl;
    cout << "Titik Tengah X : "; cin >> tx; cout << endl;
    cout << "Titik Tengah Y : "; cin >> ty; cout << endl;
}
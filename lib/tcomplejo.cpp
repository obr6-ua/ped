#include "../include/tcomplejo.h"

TComplejo::TComplejo(){
    this->im = 0;
    this->re = 0;
}

TComplejo::TComplejo(double re){
    this->re= re;
    this->im = 0;
}

TComplejo::TComplejo(double re , double im){
    this->re = re;
    this->im = im;
}

TComplejo::TComplejo(TComplejo& c){
    this->re = c.re;
    this->im = c.im;
}

TComplejo::~TComplejo(){
    this->im = 0;
    this->re = 0; 
}

TComplejo& TComplejo::operator=(TComplejo &c){
    //Si no apuntan a la misma direccion de memoria , es decir que no sean el mismo objeto , entonces 
    if(this != &c){
        (*this).~TComplejo(); //No sería necesario en esta ocasion ya que no liberamos memoria en el destructor y solo estamos reasignando
        this->re = c.re;
        this->im = c.im;
    }
    return *this;
}

TComplejo TComplejo::operator+(TComplejo &c){
    TComplejo *t = new TComplejo(c.re + this->re, this->im + c.im);
    return *t;
}

TComplejo TComplejo::operator-(TComplejo &c){
    TComplejo *t = new TComplejo(this->re - c.re, this->im - c.im);
    return *t;
}

TComplejo TComplejo::operator*(TComplejo &c){
    TComplejo *t = new TComplejo(this->re * c.re, this->im * c.im);
    return *t;
}

TComplejo TComplejo::operator+(double re){
    TComplejo *t = new TComplejo(re + this->re, this->im);
    return *t;
}

TComplejo TComplejo::operator-(double re){
    TComplejo *t = new TComplejo(this->re - re, this->im);
    return *t;
}

TComplejo TComplejo::operator*(double re){
    TComplejo *t = new TComplejo(re * this->re, this->im);
    return *t;
}

bool TComplejo::operator==(const TComplejo &c){
    if(this->im == c.im && this->re == re){
        return true;
    }
    return false;
}

bool TComplejo::operator!=(const TComplejo& c){
    return !(this==&c);
} 

double TComplejo::Re(){
    return re;
}

double TComplejo::Im(){
    return im;
}

void TComplejo::Re(double re){
    this->re = re;
}

void TComplejo::Im(double im){
    this->im = im;
}

double TComplejo::Arg(void){
    return (double)sqrt(pow(re,2) + pow(im,2));
}

double TComplejo::Mod(void){
    return (double)atan2(im , re);
}

ostream& operator<<(ostream &s, TComplejo &c){
    s << "(" << c.re << " " << c.im << ")";
    return s;
}
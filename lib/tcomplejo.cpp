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

TComplejo::TComplejo(const TComplejo& c){
    this->re = c.re;
    this->im = c.im;
}

TComplejo::~TComplejo(){
    this->im = 0;
    this->re = 0; 
}

TComplejo& TComplejo::operator=(const TComplejo &c){
    
    if(this != &c){
        (*this).~TComplejo();
        this->re = c.re;
        this->im = c.im;
    }
    return *this;
}

TComplejo operator+(double re, const TComplejo& c){
    TComplejo *t = new TComplejo(re + c.re, c.im);
    return *t;
}
TComplejo operator-(double re, const TComplejo& c){
    TComplejo *t = new TComplejo(c.re - re,c.im);
    return *t;
}
TComplejo operator*(double re, const TComplejo& c){
    TComplejo *t = new TComplejo(c.re * c.re, c.im);
    return *t;
}

TComplejo TComplejo::operator+(const TComplejo &c) {
    TComplejo *t = new TComplejo(c.re + this->re, this->im + c.im);
    return *t;
}

TComplejo TComplejo::operator-(const TComplejo &c){
    TComplejo *t = new TComplejo(this->re - c.re, this->im - c.im);
    return *t;
}

TComplejo TComplejo::operator*(const TComplejo &c){
    TComplejo *t = new TComplejo(this->re * c.re + this->im* c.im * -1,this->im * c.re + this->re * c.im);
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
    if(this->re == c.re && this->im == c.im){
        return true;
    }
    return false;
}

bool TComplejo::operator!=(const TComplejo& c){
    return !(*(this)==c);
} 

double TComplejo::Re() const{
    return re;
}

double TComplejo::Im() const{
    return im;
}

void TComplejo::Re(double re) {
    this->re = re;
}

void TComplejo::Im(double im) {
    this->im = im;
}

double TComplejo::Arg(void){
    return (double)atan2(im , re);
}

double TComplejo::Mod(void){
    return (double)sqrt(pow(re,2) + pow(im,2));
}

ostream& operator<<(ostream &s, const TComplejo &c){
    s << "(" << c.Re() << " " << c.Im() << ")";
    return s;
}
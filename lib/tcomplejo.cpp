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
    //Si no apuntan a la misma direccion de memoria , es decir que no sean el mismo objeto , entonces 
    if(this != &c){
        (*this).~TComplejo();
        this->re = c.re;
        this->im = c.im;
    }
    return *this;
}

TComplejo operator+(double d, const TComplejo &c) {
	return TComplejo(d) + c;
}

TComplejo operator-(double d, const TComplejo &c) {
	return TComplejo(d) - c;
}

TComplejo operator*(double d, const TComplejo &c) {
	return TComplejo(d) * c;
}

TComplejo TComplejo::operator+(const TComplejo &c)  {
	return TComplejo(re + c.re ,im + c.im);
}

TComplejo TComplejo::operator-(const TComplejo &c)  {
	return TComplejo(re - c.re , im - c.im);
}

TComplejo TComplejo::operator*(const TComplejo &c)  {
	return TComplejo(((re * c.re) - (im * c.im)),((re * c.im) + (im * c.re)));
}

TComplejo TComplejo::operator+(double d)  {
	return *this + TComplejo(d);
}

TComplejo TComplejo::operator-(double d)  {
	return *this - TComplejo(d);
}

TComplejo TComplejo::operator*(double d)  {
	return *this * TComplejo(d);
}

bool TComplejo::operator==(const TComplejo &c){
    if(this->re == c.re && this->im == c.im){
        return true;
    }
    return false;
}

bool TComplejo::operator!=(const TComplejo& c){
    return !(*this==c);
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
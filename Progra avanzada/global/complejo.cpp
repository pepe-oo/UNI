#include <iostream>
#include <cmath>
#include <ostream>

class Complejo
{
    private:
        double real;
        double img;
    public:
        Complejo()
        {
            real = 0;
            img = 0;
        }
        Complejo (double r, double i)
        {
            real = r;
            img = i;
        }
        double getReal() const {return real;}
        double getImg() const {return img;}
        double modulo()
        {
            return std::sqrt(std::pow(real, 2) + std::pow(img, 2)); 
        }
        Complejo conjugado() 
        {
            double img2 = this->img*(-1);
            return Complejo(this->real,img2);
        }
        Complejo operator+(const Complejo& o) const
        {
            double real2 = this->real + o.real;
            double img2 = this->img + o.img;
            return Complejo (real2, img2);
        }
        Complejo operator- (const Complejo& o) const
        {
            double real2 = this->real - o.real;
            double img2 = this->img - o.img;
            return Complejo (real2, img2);
        }
        Complejo operator* (const Complejo& o) const
        {
            double real2 = this->real*o.real - this->img*o.img;
            double img2 = this->real*o.img + this->img*o.real;
            return Complejo (real2, img2);
        }
        bool operator== (const Complejo& o ) const
        {
            bool flag_real;
            bool flag_img;
            flag_real = std::abs(this->real - o.real) < 1e-9;
            flag_img = std::abs(this->img - o.img) < 1e-9;
            return flag_img && flag_real;
        }
        friend std::ostream& operator<< (std::ostream& out, const Complejo& o)
        {
            if (o.img > 0) {out << o.real << ' + ' << o.img << 'i';}
            else if (o.img < 0) {out << o.real << ' - ' << -1 * o.img << 'i';}
            else {out << o.real;}
            out << std::endl;
            return out;
        }
};
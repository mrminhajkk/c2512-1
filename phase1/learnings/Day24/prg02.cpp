#define SUM(a, b) (a+b)
#define SQR(x) (x*x)

int main() {
    int p = SQR(SUM(2,3)); // ((2+3)*(2+3)) 
}

/*
int main() {
    int p = SQR(SUM(2,3));
}

=>


int main() {
    int p = SQR((2+3)); 
}


=>

int main() {
    int p = ((2+3)*(2+3));
}

*/
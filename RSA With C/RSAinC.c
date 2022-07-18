#include <stdio.h>
#include <math.h>
#define plaintext 25

long long getPrime(); 
long long getInverse(long long d, long long phi_n);
int isPrime(long long prime);
int rand();
int srand();
int time();
double floor(double __x);

int main(void){
    //both primenumbers are generated 
    srand(time(0));
    long long p = getPrime(42949, 10000);
    printf("Prime 1: %lld", p);
    long long q = getPrime(42949, 10000);
    printf(", Prime 2: %lld\n", q);
    //n and phi of n are calculated 
    long long n = p * q;
    long long phi_n = (p - 1) * (q - 1);
    printf("Mod n: %lld, Phi N: %lld\n", n, phi_n);
    long long lower = p;
    if(q > p){
        lower = q;
    }
    //d will be get choosen, but only a little bit higher then der biggest primenumber
    //it was easier to impliment it but it is totally unsave
    srand(time(0));
    long long d = getPrime(phi_n, lower);
    printf("d: %lld", d);
    //e is calculated
    long long e = getInverse(d, phi_n);
    printf(", e: %lld\n", e);
    if(e < 1){
        e += phi_n;
    }
    //encrypten and decrypten of the Plaintext
    long long encrypttext = 1;
    for(int i = 1; i <= d; i++){
        if((encrypttext * plaintext) > n){
            encrypttext = (encrypttext * plaintext) % n;
        }
        else{
           encrypttext = (encrypttext * plaintext);
        }
    }
    long long decrypttext = 1;
    for(int i = 1; i <= e; i++){
        if((decrypttext * encrypttext) > n){
            decrypttext = (decrypttext * encrypttext) % n;
        }
        else{
            decrypttext = (decrypttext * encrypttext);
        }
    }
    printf("PlainText: %d  EncryptedText: %lld  DecryptedText: %lld\n", plaintext, encrypttext, decrypttext);
    return 0;
}

long long getPrime(long long upper, long long lower){
    //A random number is choosen and testet if it is primenumber
    long long prime = (rand() % (upper - lower + 1)) + lower;
    if(prime % 2 == 0){
        prime += 1;
    }
    while(isPrime(prime) == -1){
        prime += 2;
    }
    return prime;
}

int isPrime(long long prime){
    //pretty inefficent but is works
    //if this part of the code would be more efficent, it would then be possible to get higher primenumber faster
    if(prime % 2 == 0|| prime % 3 == 0){
        return -1;
    }
    for (int i = 5; i < prime; i+=6){
        if (prime % i == 0 || prime % (i + 2) == 0)
            return -1;
    }
    return 0;
}

long long getInverse(long long d, long long phi_n){
    //the Inverse is calculated with help of the extended euclidean algorithm
    long long mitte = 0;
    long long rechts1 = 0;
    long long rechts2 = 1;
    while(d > 1){
        while(d <= phi_n){
            phi_n -= d;
            mitte += 1;
        }
        long long zw1 = phi_n;
        phi_n = d;
        d = zw1;
        long long rechts3 = rechts1 - (rechts2 * mitte);
        mitte = 0;
        rechts1 = rechts2;
        rechts2 = rechts3;
    }
    return rechts2;
}
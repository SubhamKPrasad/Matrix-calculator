#include <stdio.h> // Standard Input Output library ko include karta hai (printf aur scanf use karne ke liye)

int main() { // Program ka execution yahan se shuru hota hai
    int n; // Ek integer variable 'n' declare kiya gaya hai number store karne ke liye

    printf("enter a number:"); // Screen par message dikhata hai user ko number enter karne ke liye
    scanf("%d", &n); // User se input leta hai aur use variable 'n' mein store karta hai

    if(n & 1) { // Bitwise AND operator ka use karke check karta hai: agar aakhri bit 1 hai toh number Odd hai
        printf("%d is odd.\n", n); // Agar condition true hai (Odd), toh ye line print hogi
    } else { // Agar condition false hai (yani aakhri bit 0 hai)
        printf("%d is even.\n", n); // Toh ye line print hogi (Even)
    }

    return 0; // OS ko batata hai ki program sahi se execute ho gaya
}
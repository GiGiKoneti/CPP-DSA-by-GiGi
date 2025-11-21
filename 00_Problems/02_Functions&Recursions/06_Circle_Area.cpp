// Funtion to calculate the area of Circle;
# include <iostream>
using namespace std;

float CircleArea(float r) {
    if (r <= 0) {
        cout << "Invalid radius!" << endl;
        return 0.0f;
    }
    return 3.14f * r * r;
}

int main () {
    float r = 12;
    float Area = CircleArea(r);
    cout<<Area<<endl;
    return 0;
}


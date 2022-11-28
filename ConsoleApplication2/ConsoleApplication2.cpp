// The idea of that code is to compare any car specs u put to a certain car called chiron

#include <iostream>
#include <vector>
using namespace std;
//first class to input detials about the car
class productline {
private:
    //Variables about the details of the inputed car
    vector<int> priceArr;
    int productDate, engineSize,maxPow,curbWeight;
    double length, width, height, wheelBase,fuel;
public:
    string Names[9]{"Product Date","Engine Size","Max Power","Curb Weight","Length","Width","Height","Wheel base","Fuel"};
    double specs[9];        //array to add the values to it

    productline(int pd, int ES, int mX, double l, double w, double h , double wB ,int cW,double f) { // constructer which intialize take the inputes from the user , intialize it then adds it to the specs array
        setProduction(pd);
        specs[0] = pd;
        setEngineSize(ES);
        specs[1] = ES;
        setMaxPower(mX);
        specs[2] = mX;
        setDimension(l, w, h, wB);
        specs[3] = l;
        specs[4] = w;
        specs[5] = h;
        specs[6] = wB;
        setCurbWeight(cW);
        specs[7] = cW;
        setFuel(f);
        specs[8] = f;
    }
    virtual void setProduction(int pD) { // set function to set the product date
        if (pD < 2022 && pD>1886) {
            productDate = pD;
        }
        else {
            cout << "This date is not correct please choose between 1886-2022" << endl;
        }
    }
    virtual int getProduction() { // function to get the product date value
        return productDate;
        
    }
    virtual void setEngineSize(int ES) {    // set function to set the Engine size
        engineSize = ES;
    }
    virtual int getEngineSize() {   // function to get the Engine size value 
        return engineSize;
    }
    virtual void setMaxPower(int mX) {  // set function to set the Max power
        maxPow = mX;
    }
    virtual int getMaxPower() { // set function to get the max power value
        return maxPow;
    }
    virtual void setDimension(double l, double w, double h, double wB) { // set function to set the dimensions of that car
        length = l;
        width = w;
        height = h;
        wheelBase = wB;
    }
    virtual double getLength() { // function to get the length
        return length;
    }
    virtual double getWidth() { // function to get the width
        return width;
    }
    virtual double getHeight() {    // function to get the height
        return height;
    }
    virtual double getWheelBase() { //function to get the wheel base
        return wheelBase;
    }
    virtual void setCurbWeight(int cW) { //function to set the weight
        curbWeight = cW;
    }
    virtual int getCurbWeight() {   //function to get the weight
        return curbWeight;
    }
    virtual void setFuel(double f) { //function to set the fuel value
        fuel = f;
    }
    virtual int getFuel() { //function to get the fuel value
        return fuel;
    }
    virtual void printArr() {   //function to print the array that we inputed 
        for (int i = 0; i < 9; i++) {
            cout << Names[i] << "  :  " << specs[i] << endl;
        }
    }
    // all the functions of this class are virtual functions because we will override them in the next class as an example for polymorphism
};
class chiron :public productline {
private:
    //Variables about the details of the inputed car
    int productDate, engineSize, maxPow, curbWeight;
    double length, width, height, wheelBase, fuel;
public:
    chiron(int pd, int ES, int mX, double l, double w, double h, double wB, int cW, double f):productline(pd,ES,mX,l,w,h,wB,cW,f) {//intializing the variables of the base function using member intialization list 
        //setting all the values to the variables then adding it to the array to print it later
        setProduction();
        setEngineSize();
        setMaxPower();
        setDimension();
        setCurbWeight();
        setFuel();
        specs[0] = getProduction();
        specs[1] = getEngineSize();
        specs[2] = getMaxPower();
        specs[3] = getCurbWeight();
        specs[4] = getLength();
        specs[5] = getWidth();
        specs[6] = getHeight();
        specs[7] = getWheelBase();
        specs[8] = getFuel();
        
    }
    //these function have the same name as the ones in the productline class which make them overridden according to polymorphism code
    void setProduction() {  //set the product date 
        productDate = 2016;
    }
    int getProduction() {   //get the product date value
        return productDate;

    }
    void setEngineSize() {  //set the engine size value
        engineSize = 7993;
    }
    int getEngineSize() {   //get the engine size value 
        return engineSize;
    }
    void setMaxPower() {    //set the max power value
        maxPow = 1500;
    }
    int getMaxPower() {     //get the max power value
        return maxPow;
    }
    void setDimension() {   //set the dimensions for the car 
        length = 454.4;
        width = 203.8;
        height = 121.2;
        wheelBase = 271.1;
    }
    double getLength() {    //get the length of that car
        return length;
    }
    double getWidth() { //get the width of that car
        return width;
    }
    double getHeight() {    //get the height of that car
        return height;
    }
    double getWheelBase() {     //get the wheelbase of that car
        return wheelBase;
    }
    void setCurbWeight() {  //set the weight for that car
        curbWeight = 2043;
    }
    int getCurbWeight() {   //get the weight of that car
        return curbWeight;
    }
    void setFuel() {    //set the fuel capacity to that car
        fuel = 22.5;
    }
    int getFuel() {     //get the fuel value
        return fuel;
    }
    void printArr() {       //function to print the value of the array
        for (int i = 0; i < 9; i++) {
            cout << Names[i] << "  :  " << specs[i] << endl;
        }
    }

};

//class used to compare between the car supplied to the first class to the car in the second car so it gets two inhertance from both the first and the second classes
class compare :public productline, public chiron {
private:
    
public:
    //here a constructor intializting all the inherited classes in addition of getting to objects to be compared one from the first class and the second from the second class
    compare(productline firstCar,chiron secondCar, int pd, int ES, int mX, double l, double w, double h, double wB, int cW, double f):productline(pd, ES, mX, l, w, h, wB, cW, f),chiron(pd, ES, mX, l, w, h, wB, cW, f)
    {
     
    }
    //creating template here helps in the check function to accept any type of data 
    template <typename T>
    //check function checks which one is larger or even if they are equal it takes two arguments which are two objects from the two classes
    void check(T a, T b) {
        if (a == b) {
            cout << "the car u selected is equal Buggatti chiron in that aspect " << endl;
        }
        else if(a>b) {
            cout << "the car u selected is bigger Buggatti chiron in that aspect " << endl;
        }
        else if(b>a){
            cout << "the car u selected is smaller Buggatti chiron in that aspect " << endl;
        }
    }
    //here comparing between to objects of the classes and same goes for the rest of functions in that class
    void biggerProduction(productline a,chiron b) {
        check(a.getProduction(), b.getProduction());
    }
    void biggerEngineSize(productline a, chiron b) {
        check(a.getEngineSize(), b.getEngineSize());
    }
    void biggerMaxPower(productline a, chiron b) {
        check(a.getMaxPower(), b.getMaxPower());
    }
    void biggerCurbWeight(productline a, chiron b) {
        check(a.getCurbWeight(), b.getCurbWeight());
    }
    void biggerLength(productline a, chiron b) {
        check(a.getLength(), b.getLength());
    }
    void biggerWidth(productline a, chiron b) {
        check(a.getWidth(), b.getWidth());
    }
    void biggerHeight(productline a, chiron b) {
        check(a.getHeight(), b.getHeight());
    }
    void biggerWheelBase(productline a, chiron b) {
        check(a.getWheelBase(), b.getWheelBase());
    }
    void biggerFuel(productline a, chiron b) {
        check(a.getFuel(), b.getFuel());
    }
};

int main()
{   

    int choice;
    double specs[10] = {};
    //array containing the questions to get inputs to
    string questions[9] = { "Enter the product date","Enter the engine size","Enter maximum power","Enter the curb weight","Enter the length of the car","Enter the width of the car ","Enter the height of the car","Enter the wheelBase","Enter the fuel capacity" };
    //for lope to get the answers to those questions then adding them to the array specs
    for (int i = 0; i < 9; i++) {
        cout << questions[i] << endl;
        cin >> specs[i];
        system("cls");
    }
    system("cls");
    //creating two objects in the heap and intializting them by the array that we created before

    productline* firstCar=new productline(specs[0], specs[1], specs[2], specs[3], specs[4], specs[5], specs[6], specs[7], specs[8]);
    chiron* secondCar = new chiron(specs[0], specs[1], specs[2], specs[3], specs[4], specs[5], specs[6], specs[7], specs[8]);
    firstCar->printArr();
    cout<<endl;
    cout << "comparing the second car with the first one " << endl;
    secondCar->printArr();

    //creating object from the compare class to compare certain aspects int the car
    compare* a = new compare(*firstCar, *secondCar, specs[0], specs[1], specs[2], specs[3], specs[4], specs[5], specs[6], specs[7], specs[8]);
    system("pause");
    system("cls");
    //printing the aspects
    cout << "Choose an aspect to compare ur selected car with the buggatti chiron one\
             \n1.Product date\
             \n2.Engine Size\
             \n3.Maximum power\
             \n4.CurbWeight\
             \n5.Length\
             \n6.Width\
             \n7.Height\
             \n8.Wheel base\
             \n9.Fuel capacity" << endl;
    cin >> choice;
    //using switch class to choose the certain aspect u would like to compare in the two cars
    switch (choice) {
    case 1:
        a->biggerProduction(*firstCar, *secondCar);
        break;
    case 2:
        a->biggerEngineSize(*firstCar, *secondCar);
        break;
    case 3:
        a->biggerMaxPower(*firstCar, *secondCar);
        break;
    case 4:
        a->biggerCurbWeight(*firstCar, *secondCar);
        break;
    case 5:
        a->biggerLength(*firstCar, *secondCar);
        break;
    case 6:
        a->biggerWidth(*firstCar, *secondCar);
        break;
    case 7:
        a->biggerHeight(*firstCar, *secondCar);
        break;
    case 8:
        a->biggerWheelBase(*firstCar, *secondCar);
        break;
    case 9:
        a->biggerFuel(*firstCar, *secondCar);
        break;
    }
    
}

//Developed by Şerif Elashry B) thanks for reading this code <3
#include <iostream>
#include <string>
#include <vector>

#include "ShapesGood.h"


//default constructor
Shape::Shape() : length(0), width(0), borderColour(nullptr){

}


//constructor
Shape::Shape(const int& wid, const int& len, const string& bord) {
	width = new int(wid);
	length = new int(len);
	borderColour = new string(bord);

};

//Shape copy constructors
Shape::Shape(const Shape& right){
	width = new int(right.getWidth());
	length = new int(right.getLength());
	borderColour = new string(right.getBorderColour());
}

//shape destructor
Shape::~Shape(){
	delete width;
	delete length;
	delete borderColour;

	width = nullptr;
	length = nullptr;
	borderColour = nullptr;
}

//Shape assignment operator
Shape& Shape::operator=(const Shape& right){
	if(this != &right){
		delete width;
		delete length;
		delete borderColour;

		width = new int(right.getWidth());
		length = new int(right.getLength());
		borderColour = new string(right.getBorderColour());
	}
	return *this;
}


//accessors
string Filled::getFillColour() const{
	return *fillColour;
}


int Shape::getLength() const{
	return *length;
}

int Shape::getWidth() const{
	return *width;
}

string Shape::getBorderColour() const{
	return *borderColour;
}

string Text::getText() const{
	return *text;
}


//________________________________________________________________

//default constructor

Filled::Filled() : fillColour(nullptr){

}

//constructor to initialize fillColour
Filled::Filled(const string& fill){
	fillColour = new string(fill);
}

//Filled copy constructor
Filled::Filled(const Filled& right) {
fillColour = new string(right.getFillColour());
}

//Filled destructor
Filled::~Filled(){
	delete fillColour;
	fillColour = nullptr;
}

//Filled overloading assignment operator function
Filled& Filled::operator=(const Filled& right){
	if(this != &right){
		delete fillColour;
		fillColour = nullptr;
		fillColour = new string(right.getFillColour());
	}
	return *this;
}
//__________________________________________________________________________________________


//text default constructor
Text::Text() : text(nullptr){

}

//Text constructor
Text::Text(string txt){
	text = new string(txt);
}

//Text copy constructor
Text::Text(const Text& right) {
	text = new string(right.getText());
}

//Text destructor
Text::~Text(){
	delete text;
	text = nullptr;
}

//Text overloaded assignment operator
Text& Text::operator=(const Text& right){
	if(this != &right){
		delete text;
		text = nullptr;
		text = new string(right.getText());
	}
	return *this;
}

//____________________________________________________________

//square default constructor
Square::Square(const int& wid, const int& len, const string& bord) :
	Shape(wid, len, bord){
}

//Text constructor, uses Shape copy constructor
Square::Square(const Square& right) :
	Shape(right)
{
}

//Square destructor (virtual)
Square::~Square(){
}

//Square overload operator, uses overload operator of
//its base class, Shape and returns pointer to this
Square& Square::operator=(const Square& right){
	if(this != &right){
		Shape::operator=(right);
	}
	return *this;
}

//implementation of drawOutside() function in Square,
//a const function to print border colour when called in main()
void Square::drawOutside() const{
	cout << "\nDrawing a " << getBorderColour() << " square.";
}

//draw function for Square class, only calls drawOutside()
void Square::draw(){
	drawOutside();
}
//__________________________________________________________________________________


//Filled Square derives Square class and Filled class
//default constructor invokes default constructor of Square and Filled for proper attributes
FilledSquare::FilledSquare(const int& wid, const int& len, const string& bord, const string& fill) :
	Square(wid, len, bord), Filled(fill){
}

//Filled square copy constructor, invokes copy constructor of Square, Filled
FilledSquare::FilledSquare(const FilledSquare& right) :
		Square(right), Filled(right){

}

//destructor, virtual
FilledSquare::~FilledSquare(){

}

//FilledSquare overload operator, uses overload operator of
//its base class, Square and returns pointer to this
FilledSquare& FilledSquare::operator=(const FilledSquare& right){
	if(this != &right){
		Square::operator=(right);
		Filled::operator=(right);
	}
	return *this;
}

//FilledSquare instance of fill() to return the fill colour
void FilledSquare::fill(){
	cout << " With " << getFillColour() << " fill.";

}

//draw for Filledsquare, invokes drawOutside() from the Square constructor
//fill() from FilledSquare()
void FilledSquare::draw(){
	drawOutside();
	fill();
}


//___________________________________________________________________________
//FilledTextSquare derives FilledSquare class and Text class
//default constructor invokes default constructor of FilledSquare and Text for proper attributes
//FilledSquare invokes square and filled functions and text invokes text constructor
FilledTextSquare::FilledTextSquare(const int wid, const int len, const string& bord, const string& fill, const string& txt):
	FilledSquare(wid, len, bord, fill), Text(txt){
}


FilledTextSquare::~FilledTextSquare(){

}

FilledTextSquare& FilledTextSquare::operator=(const FilledTextSquare& right){
	if(this != &right){
		FilledSquare::operator=(right);
		Text::operator=(right);
	}
	return *this;
}

void FilledTextSquare::drawText(){
	cout << " Containing the text: " << "\"" << getText()  << "\".";

}

//draw() invokes drawOutside() from derived base class, Square, fill() from parent class FilledSquare
//and instaniates drawText()
void FilledTextSquare::draw() {
	drawOutside();
	fill();
	drawText();
}

//__________________________________________________________________

//the Circle and FilledCircle class follow the same methodology as the Square class
Circle::Circle( const int wid,const  int len, const string bord) :
	Shape(wid, len, bord){
}


Circle::Circle(const Circle& right) :
	Shape(right)
{
}

Circle::~Circle(){
}

Circle& Circle::operator=(const Circle& right) {
	if(this != &right){
		Shape::operator=(right);
	}
	return *this;
}

void Circle::drawOutside() const{
	cout << "\nDrawing a " << getBorderColour() << " circle.";

}

void Circle::draw(){
	drawOutside();
}
//________________________________________________________________________


FilledCircle::FilledCircle(int wid, int len, string bord, string fill) :
	Circle(wid, len, bord), Filled(fill){
}



FilledCircle::FilledCircle(const FilledCircle& right) :
	Circle(right), Filled(right) {
}

FilledCircle::~FilledCircle(){
}

FilledCircle& FilledCircle::operator=(const FilledCircle& right){
	if(this != &right){
		operator=(right);
		operator=(right);
	}
	return *this;
}

void FilledCircle::fill(){
	cout << " With " << getFillColour() << " fill.";
}

void FilledCircle::draw(){
	drawOutside();
	fill();
}

//___________________________________________________________________________________-

//the Arc class has the same implementation as the Square and Circle classes
Arc::Arc( const int wid,const  int len, const string bord) :
	Shape(wid, len, bord){
}


Arc::Arc(const Arc& right) :
	Shape(right)
{
}

Arc::~Arc(){
}

Arc& Arc::operator=(const Arc& right){
	if(this != &right){
		Shape::operator=(right);
	}
	return *this;
}

void Arc::drawOutside() const{
	cout << "\nDrawing a " << getBorderColour() << " arc.";

}

void Arc::draw(){
	drawOutside();
}



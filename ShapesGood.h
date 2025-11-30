#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Use 3 base classes, Shape, Filled, Text to be derived
//base calsses contain the virtual methods needed to implement the testing cpp
//Shape has draw(), drawOutside // Filled has fill() // Text has drawText()

class Shape {
public:
	Shape();
	Shape(const int&, const int&, const string&);
	Shape(const Shape&);
	Shape& operator=(const Shape&);
	virtual ~Shape();


	virtual void draw() = 0;
	virtual void drawOutside() const = 0;

	int getLength() const;
	int getWidth() const;
	string getBorderColour() const;

//put all attributes on the stack, which isn't necessary (for ints) but good practice
private:
	int* length;
	int* width;
	string* borderColour;

};


class Filled {
public:
	Filled();
	Filled(const string&);
	string getFillColour() const;
	Filled(const Filled&);
	Filled& operator=(const Filled&);

	virtual ~Filled();

	virtual void fill() = 0;

private:
	string* fillColour;

};

class Text {
public:
	Text();
	Text(string);
	string getText() const;

	Text(const Text&);
	Text& operator=(const Text&);

	virtual ~Text();

	virtual void drawText() = 0;

private:
	string* text;

};

//__________________________________________________________________
//The 3 shapes arc, square, circle derive shape and implement
//instances of draw() and drawOutside()

class Arc :  public Shape {
public:
	Arc(const int, const int, const string);
	Arc(const Arc& right);
	virtual ~Arc();
	Arc& operator=(const Arc&);

	void drawOutside() const;
	void draw();
};


class Square :  public Shape {
public:
	Square(const int&, const int&, const string&);
	Square(const Square&);
	virtual ~Square();
	Square& operator=(const Square&);
	void drawOutside() const;
	void draw();

};


class Circle :  public Shape {
public:
	Circle(const int, const int, const string);
	Circle(const Circle& right);
	virtual ~Circle();
	Circle& operator=(const Circle&);

	void drawOutside() const;
	void draw();

};

//__________________________________________________________________

//the FilledSquare and FilledCircle classes derive their respective shape
//Square//Circle and Filled

class FilledSquare :  public Square, public Filled {
public:
	FilledSquare(const int&, const int&, const string&, const string&);
	FilledSquare(const FilledSquare& right);
	virtual ~FilledSquare();
	FilledSquare& operator=(const FilledSquare&);

	void fill();
	void draw();
};


class FilledCircle : public Circle, public Filled {
public:
	FilledCircle( int,  int,  string,  string);

	FilledCircle(const FilledCircle& right);
	virtual ~FilledCircle();
	FilledCircle& operator=(const FilledCircle&);

	void fill();
	void draw();
};

//the FilledTextSquare class derives FilledSqaure and Text

class FilledTextSquare : public FilledSquare, public Text {
public:
	FilledTextSquare(const int, const int, const string&, const string&, const string&);

	FilledTextSquare(const FilledTextSquare& right);
	virtual ~FilledTextSquare();
	FilledTextSquare& operator=(const FilledTextSquare&);


	void drawText();
	void draw();

};





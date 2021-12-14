#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(){
	
}
Game::Game(string a, string b, string c, int d, int e, int f, double g)
	: _Name(a), _Genre(b), _Developer(c), _ReleaseYear(d), _Price(e), _NumberS(f), _Rating(g)
{

}
Game::~Game(){
	
}
void Game::setName(string a){
	this->_Name = a;
}
void Game::setGen(string b){
	this->_Genre = b;
}
void Game::setDev(string c){
	this->_Developer = c;
}
void Game::setYear(int d){
	this->_ReleaseYear = d;
}
void Game::setPrice(int e){
	this->_Price = e;
}
void Game::setSoluong(int f){
	this->_NumberS = f;
}
void Game::setRating(double g){
	this->_Rating = g;
}
string Game::getName(){
	return this->_Name;
}
string Game::getGen(){
	return this->_Genre;
}
string Game::getDev(){
	return this->_Developer;
}
int Game::getYear(){
	return this->_ReleaseYear;
}
int Game::getPrice(){
	return this->_Price;
}
int Game::getSoluong(){
	return this->_NumberS;
}
double Game::getRating(){
	return this->_Rating;
}
void Game::Show(){
	cout<<this->_Name<<" "<<this->_Genre<<" "<<this->_Developer<<" "<<this->_ReleaseYear<<" "<<this->_Price<<" "<<this->_NumberS<<" "<<this->_Rating<<endl;
}
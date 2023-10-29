import word;
import round;
import <iostream>;
import <ctime>;
import <cstdlib>;

int main() 
{
	skribble::Words test;
	test.setWords("Words.txt");
	//std::cout<<test.getWord();
	skribble::Round test2(test);
	test2.guessWord(test.getWord());
	return 0;
}
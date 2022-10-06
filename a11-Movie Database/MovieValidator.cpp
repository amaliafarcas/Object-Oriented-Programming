#include "../headers/MovieValidator.h"

using namespace std;

ValidationException::ValidationException(std::string _message) : message{ _message }
{
}

std::string ValidationException::getMessage() const
{
	return this->message;
}

ValidationExceptionInherited::ValidationExceptionInherited(std::string _message) : message{ _message }
{
}

const char* ValidationExceptionInherited::what() const noexcept
{
	return message.c_str();
}


void MovieValidator::validate(const Movie& s)
{
	string errors;
	if (s.GetTitle().size() < 2)
		errors += string("The movie name cannot be less than 2 characters!\n");
	if (s.GetGenre().size() < 2)
		errors += string("The movie genre cannot be less than 2 characters!\n");
	if (s.GetLikes() < 0)
		errors += string("The movie can not have a negative number of likes");
	if (s.GetYear() < 1895)
		errors += string("There are no movies to have come out before 1895");
	if (errors.size() > 0)
		throw ValidationException(errors);
}

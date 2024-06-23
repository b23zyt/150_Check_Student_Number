#include <iostream>
#include <climits>

#ifndef MARMOSET_TESTING
int main();
unsigned int add_checksum(unsigned int n);
void add_checksum( unsigned int array[], std::size_t capacity);
bool verify_checksum( unsigned int n );
unsigned int remove_checksum( unsigned int n );
void remove_checksum( unsigned int array[], std::size_t capacity );
#endif

unsigned int add_checksum(unsigned int n){
    if(n > 99999999){
        return 0-1;
    }else{
        bool need_double = true;
        int digit{};
        int sum{};
        int checksum_digit{};
		unsigned original_n = n;
		unsigned int result{};

        for( ; n > 0; n/=10){
            digit = n%10;

            if(need_double)
                digit *= 2;
            if (digit > 9)
                digit = (digit % 10) + 1;
            sum += digit;
            need_double = !need_double;
        }

        checksum_digit = (sum*9)%10;
		result = (original_n * 10) + checksum_digit ;
        return result;
    }
}

void add_checksum( unsigned int array[], std::size_t capacity){
    for(std::size_t i = 0; i < capacity; ++i){
        array[i] = add_checksum(array[i]);
    }
}

bool verify_checksum( unsigned int n ){
	if (n > 999999999)
		return false;

	else{
		int last_digit = n%10;
		unsigned int eight_digits = n/10;
        int checksum_digit = add_checksum(eight_digits)%10;

		if (checksum_digit == last_digit)
			return true;
		else
			return false;
	}
}

unsigned int remove_checksum( unsigned int n ){
    if (verify_checksum(n)) 
        return n/10;
    else
        return 0-1;
}

void remove_checksum( unsigned int array[], std::size_t capacity ){
    for(std::size_t i = 0; i < capacity; ++i){
        unsigned int n = array[i];

        if(verify_checksum(n))
            array[i] = n/10;
        else
            array[i] = 0-1;
    }
}

int main(){
    unsigned int a = 557555568;
    unsigned int b = verify_checksum(a);
    std::cout << b;

    return 0;
}
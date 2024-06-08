#include <any>
#include <type_traits>
#include <iostream>
#include <ranges>
#include <string_view>

int main()
{
	    auto test = std::string_view{"test"};

	     

	        std::cout << std::is_aggregate_v<decltype(std::ranges::elements_of{test})> << '\n';
		    
}

#ifndef _STREAM_CONV_HPP_
#define _STREAM_CONV_HPP_

#include <sstream>
#include <stdexcept>
#include <string>

namespace sconv {

template <typename T, typename F>
T lexical_cast(F const &value) {
	std::stringstream ss;
	T                 ret;

	ss << value;
	if (ss.fail())
		throw std::invalid_argument("conversion write to stream");
	ss >> ret;
	if (ss.fail())
		throw std::invalid_argument("conversion read from stream");
	return ret;
}
} // namespace sconv

#endif /* _STREAM_CONV_HPP_ */

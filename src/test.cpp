#include <thread>
#include "dr_log.hpp"

int main() {
	using namespace std::chrono_literals;

	dr::setupLogging("./test/test.log", "test");
	DR_DEBUG("Debug" << " message");
	DR_INFO("Info" << " message");
	DR_SUCCESS("Succes" << " message");
	DR_WARN("Warning" << " message");
	DR_ERROR("Error" << " message");
	DR_FATAL("Critical" << " message");

	constexpr int NUMBER_OF_ITERATIONS = 10;
	for (int i = 0; i < NUMBER_OF_ITERATIONS; ++i) {
		std::this_thread::sleep_for(100ms);
		DR_INFO_THROTTLE(2, "Throttled" << " at 2 Hz: " << i);
	}
}

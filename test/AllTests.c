#include "unity_fixture.h"

static	void	runAllTests(void)
{
	RUN_TEST_GROUP(stack_create);
	RUN_TEST_GROUP(stack_destroy);
}

int	main(int argc, const char **argv)
{
	return UnityMain(argc, argv, runAllTests);
}

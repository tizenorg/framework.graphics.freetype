#include <tet_api.h>

static void startup(void);
static void cleanup(void);

void (*tet_startup)(void) = startup;
void (*tet_cleanup)(void) = cleanup;

static void utc_ft_diff(void);

struct tet_testlist tet_testlist[] = {
	{ utc_ft_diff, 1 },
	{ NULL, 0 },
};

static void startup(void)
{
	/* start of TC */
}

static void cleanup(void)
{
	/* end of TC */
}

static void utc_ft_diff(void)
{
	char buf[128];
	int ret;
	sprintf(buf, "cd %s && ./ftdiff /usr/share/fonts/HelveticaNeueRegular.ttf ", getenv("FT2_TC_ROOT_PATH"));
	ret = system(buf);
	if(WEXITSTATUS(ret) == 0)
		dts_pass("utc_ft_diff");
	else
		dts_fail("utc_ft_diff");
}

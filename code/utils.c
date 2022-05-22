#include "minishell.h"

static int				ft_is_in_set(char *charset, char c)
{
	while (*charset != '\0')
	{
		if (*charset == c)
			return (1);
		++charset;
	}
	return (0);
}

static unsigned int	ft_count_part(char *str, char *charset)
{
	unsigned int	ct;

	ct = 0;
	while (*str != '\0')
	{
		if (!ft_is_in_set(charset, *str))
		{
			++ct;
			while (*str != '\0' && !ft_is_in_set(charset, *str))
				++str;
		}
		++str;
	}
	return (ct);
}

static void			ft_strncpy(char *dest, char *src, int n)
{
	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		++dest;
		++src;
		--n;
	}
	*dest = '\0';
}

char			**ft_split(char *str, char *charset)
{
	char			**ret;
	char			*cur;
	unsigned int	idx;

	ret = (char**)malloc(sizeof(char*) * ft_count_part(str, charset) + 1);
	idx = 0;
	while (*str != '\0')
	{
		if (!ft_is_in_set(charset, *str))
		{
			cur = str;
			while (*str != '\0' && !ft_is_in_set(charset, *str))
				++str;
			ret[idx] = (char*)malloc(sizeof(char) * (str - cur + 1));
			ft_strncpy(ret[idx++], cur, (str - cur));
		}
		++str;
	}
	ret[idx] = 0;
	return (ret);
}

void print_minishell()
{
    FILE* fp = fopen("name.txt", "r");  //test파일을 r(읽기) 모드로 열기
    char buffer[1000] = { 0, };

    fread(buffer, 1, 1000, fp); //전체 읽기
    printf("%s", buffer);

    fclose(fp); //파일 포인터 닫기
}

void cmd_cd(int argc, char **tokens)
{
	if (argc < 3)
		chdir(tokens[1]);
	else
		printf("wrong directory!");
}

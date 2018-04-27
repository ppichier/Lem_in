/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:10:09 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 19:32:23 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>

# define BUFF_SIZE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_struct
{
	int				*a;
	int				*count;
	char			*flag;
	int				width;
	int				precision;
	char			point;
	char			*size;
	char			conv;
}					t_struct;

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char	*dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memdup(const void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned in, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char const *s1, char const *s2);
char				*ft_strrev(char const *str);
char				*ft_strrev_free(char *str);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char splitchars);
char				*ft_itoa(int n);
char				*ft_itoa_base(int nb, int base);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					get_next_line(const int fd, char **line);
int					ft_recreate_str(char **stock, char ***line, char *buffer);
char				*ft_strcut(char *str);
int					ft_find_char(char *str);
intmax_t			ft_atoi_maxint(const char *str);
void				ft_path_x(unsigned int nb, t_struct *pattern);
void				ft_path_llx(unsigned long long int nb, t_struct *pattern);
void				ft_path_p(void *adr_ptr, t_struct *pattern);
void				ft_p_p1(t_struct *pattern, int len, void *adr_ptr);
void				ft_x_p1(unsigned int nb, t_struct *pattern, int len);
void				ft_llx_p1(unsigned long long int nb, t_struct *pattern,
					int len);
void				ft_maj_hex_wrt_ll(uintmax_t nb, t_struct *pattern);
void				ft_hex_wrt_ll(uintmax_t nb, t_struct *pattern);
char				*ft_hex_wrt(uintmax_t nb, t_struct *pattern);
char				*ft_maj_hex_wrt(uintmax_t nb, t_struct *pattern);
void				ft_put_diese_hex(t_struct *pattern);
void				ft_check_diese(t_struct *pattern, int len);
void				ft_printp_prec(t_struct *pattern, int len);
void				ft_printh_prec1(t_struct *pattern, int len);
void				ft_printh_prec2(t_struct *pattern, int len);
void				ft_printh_width(t_struct *pattern, int len, uintmax_t nb);
void				ft_printh_width1(t_struct *pattern, int len, uintmax_t nb);
void				ft_printh_width2(t_struct *pattern, int len);
void				ft_printh_width_0(t_struct *pattern, int len, uintmax_t nb);
void				ft_printh_width_01(t_struct *pattern, int len);
void				ft_printh_width_02(t_struct *pattern, int len);
void				ft_printh_width_03(t_struct *pattern, int len);
void				ft_printh_width_03b(t_struct *pattern, int len);
void				ft_printh_width_04(t_struct *pattern, int len);
void				ft_printh_width_04b(t_struct *pattern,
					int len, uintmax_t nb);
void				ft_printh_width_04c(t_struct *pattern,
					int len, uintmax_t nb);
void				ft_printh_prec_rev(t_struct *pattern, int len);
void				ft_path_i_d(intmax_t nb, t_struct *pattern);
int					ft_path_size_d(intmax_t nb, t_struct *pattern);
int					ft_path_size_u(intmax_t nb, t_struct *pattern);
void				ft_path_u(int nb, t_struct *pattern);
void				ft_path_lu(uintmax_t nb, t_struct *pattern);
void				ft_path_llu(intmax_t nb, t_struct *pattern);
void				ft_putnbr_maxun_count(uintmax_t nb, t_struct *pattern);
void				ft_putnbr_max_count(intmax_t nb, t_struct *pattern);
int					ft_int_len_base(intmax_t nb, int base);
void				ft_put_sign(intmax_t nb, t_struct *pattern);
int					ft_unint_len_base(uintmax_t nb, int base);
void				ft_check_sign(intmax_t nb, t_struct *pattern, int len);
void				ft_check_space(intmax_t nb, t_struct *pattern);
void				ft_printd_prec(intmax_t nb, t_struct *pattern, int len);
void				ft_printd_prec1(intmax_t nb, t_struct *pattern, int len);
void				ft_printd_prec2(intmax_t nb, t_struct *pattern, int len);
void				ft_printd_width(intmax_t nb, t_struct *pattern, int len);
void				ft_printd_width1(intmax_t nb, t_struct *pattern, int len);
void				ft_printd_width2(intmax_t nb, t_struct *pattern, int len);
void				ft_printd_width_0(intmax_t nb, t_struct *pattern, int len);
void				ft_printd_width_01(intmax_t nb, t_struct *pattern, int len);
void				ft_printd_width_02(intmax_t nb, t_struct *pattern, int len);
void				ft_printd_width_02b(intmax_t nb,
					t_struct *pattern, int len);
void				ft_printd_width_03(intmax_t nb, t_struct *pattern, int len);
void				ft_printd_width_04(intmax_t nb, t_struct *pattern, int len);
void				ft_printd_width_05(intmax_t nb, t_struct *pattern, int len);
void				ft_printd_prec_rev(t_struct *pattern, int len);
void				ft_path_o(uintmax_t nb, t_struct *pattern);
void				ft_path_wo(uintmax_t nb, t_struct *pattern);
void				ft_path_llo(unsigned long long int nb, t_struct *pattern);
void				ft_llo_p1(unsigned long long int nb, t_struct *pattern,
					int len);
void				ft_o_p1(uintmax_t nb, t_struct *pattern, int len);
void				ft_wo_p1(uintmax_t nb, t_struct *pattern, int len);
char				*ft_octal_wrt(uintmax_t nb, t_struct *pattern);
void				ft_put_0_o(t_struct *pattern);
void				ft_checko_0(t_struct *pattern, int len);
void				ft_printo_prec1(t_struct *pattern, int len);
void				ft_printo_prec2(t_struct *pattern, int len);
void				ft_printo_width(t_struct *pattern, int len, uintmax_t nb);
void				ft_printo_width1(t_struct *pattern, int len, uintmax_t nb);
void				ft_printo_width2(t_struct *pattern, int len);
void				ft_printo_width_0(t_struct *pattern, int len);
void				ft_printo_width_01(t_struct *pattern, int len);
void				ft_printo_width_02(t_struct *pattern, int len);
void				ft_printo_width_03(t_struct *pattern, int len);
void				ft_printo_width_03b(t_struct *pattern, int len);
void				ft_printo_width_04(t_struct *pattern, int len);
void				ft_printo_width_04b(t_struct *pattern, int len);
void				ft_printo_prec_rev(t_struct *pattern, int len);
void				ft_path_c(int c, t_struct *pattern);
int					ft_path_wc(wchar_t c, t_struct *pattern);
void				ft_path_s(char *str, t_struct *pattern);
int					ft_path_ws(int *nb, t_struct *pattern);
void				ft_ws_p1(t_struct *pattern, int len);
void				ft_s_p1(t_struct *pattern, int len);
void				ft_str_wrt(char *str, t_struct *pattern);
void				ft_strwrt(char *str, t_struct *pattern);
void				ft_putwchar(wchar_t nb, t_struct *pattern);
void				ft_putwstr(int *tab, t_struct *pattern);
void				ft_putwstr1(wchar_t *tab, t_struct *pattern);
int					ft_wstrlen(wchar_t *nb);
int					ft_wcharlen(wchar_t nb);
int					ft_calc_len(int *tab, t_struct *pattern);
void				ft_putwchar3(wchar_t nb, t_struct *pattern);
void				ft_putwchar4(wchar_t nb, t_struct *pattern);
int					ft_check_error_wc (wchar_t c);
int					ft_check_error_strwc(wchar_t *tab, int len);
void				ft_printc_prec1(t_struct *pattern, int len);
void				ft_printc_prec2(t_struct *pattern, int len);
void				ft_printc_width(t_struct *pattern, int len);
void				ft_printc_width1(t_struct *pattern, int len);
void				ft_printc_width2(t_struct *pattern, int len);
void				ft_printc_width_0(t_struct *pattern, int len);
void				ft_printc_width_01(t_struct *pattern, int len);
void				ft_printc_width_02(t_struct *pattern, int len);
void				ft_printc_width_03(t_struct *pattern, int len);
void				ft_printc_width_04(t_struct *pattern, int len);
void				ft_printc_width_04b(t_struct *pattern, int len);
void				ft_printc_prec_rev(t_struct *pattern, int len);
void				ft_printc_prec_rev1(t_struct *pattern, int len);
void				ft_pattern_struct(const char *restrict str,
					t_struct *pattern);
void				ft_struct_conv(t_struct *pattern, const char *restrict str);
void				ft_struct_size(t_struct *pattern, const char *restrict str);
void				ft_struct_prec(t_struct *pattern, const char *restrict str);
void				ft_struct_width(t_struct *pattern,
					const char *restrict str);
void				ft_struct_flag(t_struct *pattern, const char *restrict str);
t_struct			*ft_create_struct(t_struct *pattern, int *a, int *count);
void				ft_clean_struct(t_struct *pattern);
void				ft_free_struct(t_struct *pattern);
void				ft_path_e(t_struct *pattern);
int					ft_printf(const char *restrict format, ...);
void				ft_putchar_st(char c, t_struct *pattern);
int					ft_check_char(char c);
void				ft_check_int(intmax_t nb, t_struct *pattern);
int					ft_find_path(va_list ap, t_struct *pattern);
void				ft_check_un(uintmax_t nb, t_struct *pattern);
int					ft_check_char_w(char c);
int					ft_check_wswc(intmax_t nb, t_struct *pattern);
int					ft_check_char_int(char c);
int					ft_check_char_un(char c);
int					ft_printf_loop(t_struct *pattern,
					const char *restrict format, va_list ap);
void				ft_swap(int *a, int *b);

#endif

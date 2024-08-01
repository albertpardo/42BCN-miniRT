/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:57:56 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/01 18:46:36 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define BAD_ARGUMENTS "BAD ARGUMETS. Use : ./minirt NAME.rt"
# define NO_OPEN "open() failed"
# define NO_CLOSE "\nclose() failed" 
# define MALLOC_ERROR "Memory assignament ERROR"
# define BAD_FILETYPE "Filetype is not .rt"
# define EMPTY_FILE "Empty file."
# define SPACES_IN_FILE "File only with 'spaces' and/or '\\t' and '\\n'." 
# define EXT ".rt"
# define ID_ERROR_NOALPHA "Element ID is no alpha"
# define NO_ELEMENT "NO ELEMENT"
# define ERR_NUM_TYPELEM_AMBIENT "[Ambient]: No Scale or RGB"
# define ERR_NUM_TYPELEM_CAMARA "[Camara]: No Viewport, Orientation or RGB"
# define ERR_NUM_TYPELEM_LIGHT "[Light]: No Lightpoint, Brigh Ratio or RGB"
# define ERR_NUM_TYPELEM_SPHERE "[Sphere]: No Center, Diameter or RGB"
# define ERR_NUM_TYPELEM_PLANE "[Plane]: No Point in plane, Normalized Normal or RGB"
# define ERR_NUM_TYPELEM_CYLINDRE "[Cylindre]: No Center, Normalized Vector, Diameter,Height or RGB"

// --- Defines for integers checks ----- //

# define CHAR_MAX_RGB "255"
# define CHAR_MAX_FOV "180"
# define INT_NUMDIGITS 3

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

// ---- Diferent elements structs ---- //

typedef struct s_ambientlight
{
	float		lightradio;
	t_vector3	f_rgb;
}	t_ambientlight;

typedef struct s_camera
{
	t_vector3	viewpoint;
	t_vector3	orient;
	float		fov;
}	t_camera;

typedef struct s_light
{
	t_vector3	lightpoint;
	float		brightratio;
	t_vector3	f_rgb;
}	t_light;

typedef struct s_sphere
{
	t_vector3	center;
	float		diameter;
	t_vector3	f_rgb;
}	t_sphere;

typedef struct s_plane
{
	t_vector3	point;
	t_vector3	normal;
	t_vector3	f_rgb;
}	t_plane;

typedef struct s_cylinder
{
	t_vector3	center;
	float		diameter;
	float		height;
	t_vector3	normvector;
	t_vector3	f_rgb;
}	t_cylinder;

// ---- Generic element struct ---- //

typedef struct s_element
{
	int		idnum;
	char	idelement;
	void	*infoelement;
}	t_element;

// ---- Only Element struct ------ //

typedef struct s_onlyelem
{
	int			isset;
	t_element	element;
}	t_onelem;

// ---- Scene struct ---- //

typedef struct s_sceneinf
{
	t_onelem	amb;
	t_onelem	cam;
	t_onelem	light;
	t_element	*elemlst;
}	t_scinf;

// ------  parsing -------- //

void	checka(char **aelement);
void	checkc(char **aelement);
void	checkcy(char **aelement);
void	checkl(char **aelement);
void	checkpl(char **aelement);
void	checksp(char **aelement);
void	checkidvalid(char **elem);
char	*cleanstringspaces(char *str);
size_t	countchar(char *str, char c);
void	exiterror(char *msg);
void	exitifcheckfails(int val, char *msg);
void	exitifnotvalidfiletype(char *fname, char *ext, char *msg);
void	exitifnortfile(char *filename);
void	freearrstr(char **arr);
int		ft_astrlen(char **arrstr);
int		ft_isspace(const char c);
int		ft_isstralpha(char *str);
int		ft_strichr(const char *s, int c);
int		iscoordinatestr(char *str);
int		isfov(char *str);
int		isorientnormal(char *str);
int		isrgbstr(char *str);
int		isstringvalueinpositiverange(char *str, char *maxintval);
int		isstrfloat(char *str);
int		isstrfloatcerone(char *str);
int		isstrfloatsgnone(char *str);
//int		isstrsgnfloat(char *str);
int		isstrsgnfloat(char *str, int onlyplus);
void	putarraystr(char **arrstr);

#endif

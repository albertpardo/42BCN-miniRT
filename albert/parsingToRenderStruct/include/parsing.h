/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:04:29 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/01 09:32:11 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "vector3.h"



// --- Error values when check elements from file ---//

# define VALID_ELEMENT 0
# define ERR_IN_FORMAT 1
# define ERR_NORM_VECTOR_CERO 2

// --- Error Messages asociated to Error values ---//

# define MSG_ERR_IN_FORMAT "The next Element line is not valid format:"
# define MSG_ERR_NORM_VECTOR_CERO "'NO VALID 0,0,0 Normal Vector' in line:"


// --- Error Mesages --- //

# define BAD_ARGUMENTS "BAD ARGUMETS. Use : ./minirt NAME.rt"
# define NO_OPEN "open() failed"
# define NO_CLOSE "\nclose() failed" 
# define MALLOC_ERROR "Memory assignament ERROR"
# define BAD_FILETYPE "Filetype is not .rt"
# define EMPTY_FILE "Empty file."
# define SPACES_IN_FILE "File only with 'spaces' and/or '\\t' and '\\n'." 
# define ID_ERROR_NOALPHA "Element ID is no alpha"
# define NO_ELEMENT "NO ELEMENT"
# define ERR_TYPO_ELEM "The next Element line is not valid format :"
# define ERR_TYPO_AMBIENT "[Ambient]: No Scale or RGB"
# define ERR_TYPO_CAMARA "[Camara]: No Viewport, Orientation or RGB"
# define ERR_TYPO_LIGHT "[Light]: No Lightpoint, Brigh Ratio or RGB"
# define ERR_TYPO_SPHERE "[Sphere]: No Center, Diameter or RGB"
# define ERR_TYPO_PLANE "[Plane]: No PointPlane, NormalizedNormal or RGB"
# define ERR_TYPO_CYL "[Cyl]: No Center,NormalizedVector,Diameter,Height or RGB"
# define ERR_DUP_AMB "Ambient Light is duplicated in the file"
# define ERR_DUP_CAM "Camara is duplicated in the file"
# define ERR_DUP_LIG "Light is duplicated in the file"
# define ERR_NO_AMB "Ambient Light is no defined in the file"
# define ERR_NO_CAM "Camara is no defined in the file"
# define ERR_NO_LIG "Light is no defined in the file"

// --- Define for typo file check --- //

# define EXT ".rt"

// --- Defines for integers checks ----- //

# define CHAR_MAX_RGB "255"
# define CHAR_MAX_FOV "180"
# define INT_NUMDIGITS 3

/*
 * Struct used in parsing for set elements in scene
 *
 * - ln : one line from input file
 * - cln: 'ln' copy with only one space between valid type data
 * - astr: an string pointer done with ft_split from 'cln' 
 */

typedef struct s_parsing
{
	char	*ln;
	char	*cln;
	char	**astr;
}	t_pars;

// ---- Diferent elements structs ---- //

/*  Ambient , camera & ligth has their own complete struct
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
*/

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
	t_vector3	normvector;
	float		diameter;
	float		height;
	t_vector3	f_rgb;
}	t_cylinder;

// ---- Generic element struct ---- //

typedef struct s_element
{
	int		idnum;
	char	*idelement;
	void	*infoelement;
}	t_element;

// ---- Only Element struct ------ //

/* Used for Amb, cam, or ligth  NO NECESARY???
typedef struct s_onlyelem
{
	int			isset;
	t_element	element;
}	t_onelem;
*/

// id could be redundant

typedef struct s_amb
{
	int			isset;
	char		*id;
	float		ratio;
	t_vector3	f_rgb;
}	t_amb;

// id could be redundant

typedef struct s_cam
{
	int			isset;
	char		*id;
	t_vector3	viewpoint;
	t_vector3	orient;
	float		fov;
}	t_cam;

// id could be redundant

typedef struct s_light
{
	int			isset;
	char		*id;
	t_vector3	lightpoint;
	float		ratio;
	t_vector3	f_rgb;
}	t_light;

// ---- Scene struct ---- //

typedef struct s_sceneinf
{
	t_amb	amb;
	t_cam	cam;
	t_light	light;
	t_list	*elemlst;
}	t_sceneinf;

// ------  parsing -------- //

// Start  - Validate elements   //

int		checkiselement(char **elem);
int		checkisambient(char **aelement);
int		checkiscamara(char **aelement);
int		checkislight(char **aelement);
int		checkisplan(char **aelement);
int		checkisspher(char **aelement);
int		checkiscylin(char **aelement);

// End  - Validate elements   //

char	*cleanstringspaces(char *str);
void	clearscene(t_sceneinf *scene);
size_t	countchar(char *str, char c);
void	exiterror(char *msg);
void	exiterrorfreemsg(char *msg);
void	exiterror_line_freemsg(char *line, char *msg);
void	exitifcheckfails(int val, char *msg);
void	exitifnotvalidfiletype(char *fname, char *ext, char *msg);
void	exitifnortfile(char *filename);
void	freearrstr(char **arr);
char	*freecleanlineandgetnl(char *cleanstr, char *line, int fd);
void	freelinscenfdexitbymalloc(char *line, t_sceneinf *scene, int fd);
void	freescnparsfdexitmsg(char *msg, t_sceneinf *scn, t_pars *pars, int fd);
//void	freesplitcleanscenefd(char **arr, char *str, t_sceneinf *scn, int fd);
void	free_scnparsfd(t_sceneinf *scn, t_pars *pars, int fd);
void	free_exit_elementerr(char *msg, t_sceneinf *scn, t_pars *pars, int fd);
void	free_exit_normalcero(char *msg, t_sceneinf *scn, t_pars *pars, int fd);
int		ft_astrlen(char **arrstr);
int		ft_isspace(const char c);
int		ft_isstralpha(char *str);
int		ft_strichr(const char *s, int c);
int		iscoordinatestr(char *str);
int		isfov(char *str);
int		checkisnormal(char *str);
//int		isorientnormal(char *str);
int		isrgbstr(char *str);
int		isstringvalueinpositiverange(char *str, char *maxintval);
int		isstrfloat(char *str);
int		isstrfloatcerone(char *str);
int		isstrfloatsgnone(char *str);
//int		isstrsgnfloat(char *str);
int		isstrsgnfloat(char *str, int onlyplus);
void	setambient(char **aelement, t_sceneinf *scene);
void	setcamara(char **aelement, t_sceneinf *scene);
void	setcylinder(char **aelement, t_sceneinf *scene);
void	setelementinscene(char **eaelement, t_sceneinf *scene);
void	setlight(char **aelement, t_sceneinf *scene);
void	setnormalrgb(char *str, t_vector3 *rgb);
void	setplane(char **aelement, t_sceneinf *scene);
void	setsceneorexit(int argc, char *scfile, t_sceneinf *scene);
void	setsphere(char **aelement, t_sceneinf *scene);
void	setvectorinelemtscene(char *strvect, t_vector3 *vec3);
void	putarraystr(char **arrstr);

#endif

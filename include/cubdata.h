/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBDATA_H
# define CUBDATA_H

# define KEYLEFT 0xFF51
# define KEYRIGHT 0xFF53
# define KEYA 0x0061
# define KEYB 0x0062
# define KEYC 0x0063
# define KEYD 0x0064
# define KEYE 0x0065
# define KEYF 0x0066
# define KEYG 0x0067
# define KEYH 0x0068
# define KEYI 0x0069
# define KEYJ 0x006A
# define KEYK 0x006B
# define KEYL 0x006C
# define KEYM 0x006D
# define KEYN 0x006E
# define KEYO 0x006F
# define KEYP 0x0070
# define KEYQ 0x0071
# define KEYR 0x0072
# define KEYS 0x0073
# define KEYT 0x0074
# define KEYU 0x0075
# define KEYV 0x0076
# define KEYW 0x0077
# define KEYX 0x0078
# define KEYY 0x0079
# define KEYZ 0x007A
# define KEYESC 0xFF1B
# define KEYSHIFT 0xFFE1
# define PI 0.0174532925

typedef unsigned int	t_ui;

typedef struct	s_sprites
{
	int			num;
	int			all_s;
	int			*height;
	int			*x;
}				t_sprites;

typedef struct	s_cub
{
	void		*mlx;
	void		*win;
	char		**map;
	int			key_a;
	int			key_d;
	int			key_w;
	int			key_s;
	int			key_left;
	int			key_right;
	double		alpha;
	double		beta;
	double		dir_angle;
	double		pdx;
	double		pdy;
	double		pdx2;
	double		pdy2;
	double		pos_x;
	double		pos_y;
	double		step_map;
	double		t_view;
	int			num_wall;
	int			column;
	double		h_wall;
	double		delta;
	double		map_x;
	double		map_y;
	double		map_size_x;
	double		map_size_y;
	int			start;
	t_ui		**data_t[5];
	int			f_col[3];
	t_ui		f_c;
	int			c_col[3];
	t_ui		c_c;
	int			t_w[5];
	int			t_h[5];
	void		*tex[5];
	int			bpp[5];
	int			sl;
	int			e;
	int			map_var[8];
	void		*img;
	t_ui		**data_img;
	void		*minimap;
	t_ui		**data_map;
	int			i_bpp;
	int			width;
	int			height;
	int			len;
	double		dist;
	double		speed;
	double		speed_alpha;
	int			m_map;
	int			check;
	int			error;
	t_sprites	sprites;
}				t_cub;

#endif

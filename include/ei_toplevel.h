#include "ei_widget.h"
typedef struct ei_toplevel_t {
    ei_widget_t widget;
    ei_size_t requested_size;
    ei_color_t color;
    int border_width;
    char *title;
    ei_bool_t closable;
    ei_axis_set_t resizable;
    ei_size_t *min_size;

} ei_toplevel_t ;

struct ei_widget_t* toplevel_allocfunc_t(void);

void toplevel_releasefunc_t(struct ei_widget_t * widget);

void    toplevel_drawfunc_t	(struct ei_widget_t *	widget,
                                ei_surface_t		surface,
                                ei_surface_t		pick_surface,
                                ei_rect_t*		clipper);

void toplevel_setdefaultsfunc_t	(struct ei_widget_t *widget);


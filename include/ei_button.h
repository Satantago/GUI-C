#include "ei_widget.h"
#include "stdlib.h"
#include "ei_widgetclass.h"

typedef struct ei_button_t
{
    ei_widget_t     widget        ;
    ei_color_t	    color         ;
    int		        border_width  ;
    int	            corner_radius ;
    ei_relief_t	    relief        ;
    char*	        text          ;
    ei_font_t	    text_font     ;
    ei_color_t      text_color    ;
    ei_anchor_t		text_anchor   ;
    ei_surface_t	 img          ;
    ei_rect_t*	     img_rect     ;
    ei_anchor_t	     img_anchor   ;
    ei_callback_t    callback     ;


}ei_button_t;

struct ei_widget_t* button_allocfunc_t(void);
void button_releasefunc_t(struct ei_widget_t * button);

void    button_drawfunc_t	(struct ei_widget_t *	widget,
                             ei_surface_t		surface,
                             ei_surface_t		pick_surface,
                             ei_rect_t*		clipper);
void button_setdefaultsfunc_t	(struct ei_widget_t *button);

void button_geomnotifyfunc_t(struct ei_widget_t* button);
ei_linked_point_t *arc(ei_point_t centre, int rayon, double angle_debut, double angle_fin);

ei_linked_point_t rounder_frame(ei_point_t centre, int rayon, double angle_debut, double angle_fin);

int abscisse(int x_centre, int radius, double angle);

int ordonnee(int y_centre, int radius, double angle);

void print_surface(ei_surface_t surface);

ei_linked_point_t *queue(ei_linked_point_t *points);

void inserer_queue(struct ei_linked_point_t **pl, int x, int y);

ei_linked_point_t *inserer_tete(struct ei_linked_point_t *pl, int x, int y);

ei_linked_point_t *rounded_frame(ei_rect_t rectangle, int rayon_arrondi, char *precision);

ei_color_t foncer_couleur(ei_color_t color);

ei_color_t clair_couleur(ei_color_t color);

ei_bool_t bouton_enfonce(ei_widget_t *widget, struct ei_event_t *event, void *user_param);
ei_bool_t bouton_relache(ei_widget_t *widget, struct ei_event_t *event, void *user_param);


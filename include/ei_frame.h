#include "ei_widget.h"
#include "stdlib.h"
#include "ei_widgetclass.h"
#include "ei_types.h"
#include "ei_event.h"

typedef struct event_type_data{
    void *user_param;
    ei_callback_t callback;
    ei_widget_t *widget;
    ei_tag_t tag;
    struct event_type_data *prec;
    struct event_type_data *next;
}event_type_data;

typedef struct type_managed{
    event_type_data *callbacks;
    ei_eventtype_t type;
    struct type_managed *next;
}type_managed;
//type_managed *manager = NULL;
// creation de la sous-classe frame
typedef struct ei_frame_t{
    ei_widget_t widget;
    int border_width;
    ei_color_t color;
    ei_relief_t relief;
    ei_color_t text_color;
    ei_font_t  text_font;
    ei_anchor_t 	text_anchor;
    ei_surface_t *  	img;
    ei_rect_t *  	img_rect;
    ei_anchor_t   	img_anchor;
    char *  	text;
}ei_frame_t;

struct ei_widget_t* frame_allocfunc_t(void);
void frame_releasefunc_t(struct ei_widget_t * frame);

void    frame_drawfunc_t	(struct ei_widget_t *	widget,
							 ei_surface_t		surface,
							 ei_surface_t		pick_surface,
							 ei_rect_t*		clipper);
void frame_setdefaultsfunc_t	(struct ei_widget_t *frame);

void	frame_geomnotifyfunc_t	(struct ei_widget_t*	widget);

void draw_hierarchie(ei_widget_t *widget, ei_surface_t offscreen, ei_rect_t *rect);

ei_widget_t *recherche_id(ei_widget_t *widget, uint32_t pick_id);

ei_rect_t *parent_screen_location(ei_widget_t *widget);

void ajoute_fils(ei_widget_t *widget_parent, ei_widget_t *widgetFils);

ei_color_t *couleur(uint32_t id);
ei_surface_t ei_app_offscreen(void);

event_type_data *analyse_event(ei_event_t *event);
void execute_callbacks(event_type_data *callbacks, ei_event_t *event);

type_managed *typeManaged(void);
void ajoute_queue_event_type(event_type_data **pl,
					 ei_widget_t*		widget,
					 ei_tag_t		tag,
					 ei_callback_t		callback,
					 void*			user_param);
void ajoute_queue_type_managed(type_managed **pl,ei_eventtype_t eventtype, event_type_data *callbacks);

ei_bool_t parcourt_hierarchie(ei_widget_t *widget, ei_tag_t tag, ei_bool_t eiBool, event_type_data *callbacks, ei_event_t *event);

ei_rect_t *ei_rect_widget(ei_widget_t *widget);

ei_linked_point_t *dessine_rectangle(ei_rect_t rect, char *precision);

void  draw_image(ei_surface_t surface, ei_surface_t *img,ei_rect_t *img_rect,ei_anchor_t img_anchor);

ei_bool_t quit(ei_widget_t* widget, ei_event_t* event, void* user_param);

ei_bool_t debut_deplacement(ei_widget_t *widget, struct ei_event_t *event, void *user_param);

ei_bool_t fin_deplacement(ei_widget_t *widget, struct ei_event_t *event, void *user_param);

ei_bool_t deplacement_move(ei_widget_t *widget, struct ei_event_t *event, void *user_param);

ei_bool_t debut_redimensionnement(ei_widget_t *widget, struct ei_event_t *event, void *user_param);

ei_bool_t fin_redimensionnement(ei_widget_t *widget, struct ei_event_t *event, void *user_param);

ei_bool_t redimensionnement_move(ei_widget_t *widget, struct ei_event_t *event, void *user_param);

ei_point_t where_from_func(void);

void delete_from_screen(ei_widget_t *widget);

ei_widget_t *widget_picked(ei_widget_t *widget, uint8_t red, uint8_t blue, uint8_t green);

int min(int a, int b);

int max(int a, int b);


int size_of(ei_linked_rect_t *rect_list);

void changement_chainage(ei_widget_t *widget);

ei_rect_t intersection(ei_rect_t premier_rect , ei_rect_t deux_rect);

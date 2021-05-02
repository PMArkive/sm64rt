#ifndef GFX_PC_H
#define GFX_PC_H

#include "gfx_rendering_api_config.h"

struct GfxRenderingAPI;
struct GfxWindowManagerAPI;

struct GfxDimensions {
    uint32_t width, height;
    float aspect_ratio;
};

extern struct GfxDimensions gfx_current_dimensions;

#ifdef __cplusplus
extern "C" {
#endif

void gfx_init(struct GfxWindowManagerAPI *wapi, struct GfxRenderingAPI *rapi, const char *window_title);
struct GfxRenderingAPI *gfx_get_current_rendering_api(void);
void gfx_start_frame(void);
void gfx_run(Gfx *commands);
void gfx_end_frame(void);
void gfx_precache_textures(void);
void gfx_shutdown(void);

#ifdef GFX_SEPARATE_PROJECTIONS
void gfx_set_camera_perspective(float fov_degrees, float near_dist, float far_dist);
void gfx_set_camera_matrix(float mat[4][4]);
#ifdef GFX_ENABLE_PREVIOUS_FRAME_MOTION
#define G_MTX_PREV   0x08
void gfx_set_camera_perspective_previous(float fov_degrees, float near_dist, float far_dist);
void gfx_set_camera_matrix_previous(float mat[4][4]);
#endif
#endif

#ifdef GFX_ENABLE_GRAPH_NODE_MODS
void gfx_push_geo_layout(void *geo_layout);
void gfx_register_graph_node_layout(void *graph_node);
void gfx_pop_geo_layout(void);
void *gfx_get_graph_node_mod(void *graph_node);
#endif

#ifdef __cplusplus
}
#endif

#endif

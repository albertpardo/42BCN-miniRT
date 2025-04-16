#include "miniRT.h"
//0. guardar datos en memoria
//1. crear renderer
//2. camara(posicion, quaternion(rotacion), planoCercano, planoLejano, fov)
//3. setear la luz ambiental con ambient_light(1, color), para setearla usar vector_scale(color, intensidad)
//4. crear una t_pointlight, parametros son posicion, radio(6), intensidad (multiplicar numero(0-1) por 60), y luego poner light count a 1
//5. reservar memoria para un puntero de objetos, calcular cantidad de objetos
//6. crear, rotar, y mover;
//	PARA CREAR:
//	generate_cylinder(t_object *, altura, radio, segmentos);
//	create_sphere_mesh(t_object *, radius);
//	create_plane_mesh(t_object *, size, size);
//	PARA ROTAR:
//	rotate_object(t_object *, vector de orientacion);
//	PARA MOVER:
//	translate_object(t_object *, punto del objeto);
//	SET COLOR
//	objeto.color = nuevo color(rango 0-1) en vector3;
//7. rellenar la variable t_global con los valores correspondientes
//8. llamar al render con el global

int main() {
    t_renderer renderer;
    renderer.width = 1000;
    renderer.height = 1000;
    renderer.mlx = mlx_init();
    renderer.win = mlx_new_window(renderer.mlx, renderer.width, renderer.height, "Ray Tracer");
    renderer.img = mlx_new_image(renderer.mlx, 1000, 1000);
    renderer.addr = mlx_get_data_addr(renderer.img, &renderer.bits_per_pixel, &renderer.line_length,&renderer.endian);
    //
    t_camera camera = {{0, 5,11}, {-0.2164396, 0, 0, 0.976296}, 0.000001f, 100.0f, 60.0f};
    //
    ambient_light(1, (t_vector3) {0.5, 0.5, 0.5});
    //
    t_object sphere2;
    t_object plane;
    t_object cylinder;
    generate_cylinder(&cylinder, 1,1.8,18);
    create_plane_mesh(&plane, 20, 20);
    create_sphere_mesh(&sphere2, 1);
    //
    sphere2.color = (t_vector3) {1,0,0};
    plane.color = (t_vector3) {0,1,0};
    //rotate_object(&plane, (t_vector3){0.5, 0.5, 0.0});
    translate_object(&plane, (t_vector3){5,-2.5,5});
    translate_object(&cylinder, (t_vector3){2,-1,2.5});
    translate_object(&sphere2, (t_vector3){-2,-0.5,2.5});
    cylinder.color = (t_vector3) {0,1,1};
    //
    t_object objects[] = {sphere2, plane, cylinder};
    int object_count = sizeof(objects) / sizeof(objects[0]);
    t_pointlight light = {{-3, 0.5, 2}, 5.2f, 600.0f};
    t_pointlight light2 = {{3, 0.5, 2}, 5.2f, 600.0f};
    t_pointlight light3 = {{0, 0.6, 0}, 6.0f, 25.0f};//refeerencia valores finales de luz
    t_pointlight light4;
    light4 = (t_pointlight) {(t_vector3){0, 1, 4}, 6.0f, 60.0f};
	// several ligths
    //t_pointlight lights[] = {light, light2, light3, light4};
    //int light_count = sizeof(lights) / sizeof(lights[0]);
    
    //
    t_global el_global;
    el_global.renderer = &renderer;
    el_global.camera = &camera;
    el_global.objects = &objects[0];
    el_global.object_count = object_count;
	//One ligth
    el_global.lights = &light4;
    el_global.light_count = 1;
    //
    //t_pointlight lights[] = {light4};
    render_scene(&el_global);
    mlx_put_image_to_window(renderer.mlx, renderer.win, renderer.img, 0, 0);
    mlx_loop(renderer.mlx);
    free(renderer.framebuffer);
    return 0;
}

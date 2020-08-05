library(rayrender)

scene = sphere(y=-1001,radius=1000,
               material = lambertian(color = "#ccff00",checkercolor="grey50")) %>%
  add_object(sphere(material=lambertian(color="#dd4444")))
render_scene(scene, width=500, height=500, samples=500)
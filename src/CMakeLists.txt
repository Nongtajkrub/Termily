project("Termily")

add_executable(
    "Termily"
    "Termily/Graphic/graphic.c"
    "Termily/Actor/actor.c"
    "Termily/Key/key.c"
    "Termily/Mouse/mouse.c"
    "Termily/Sound/sound.c"
    "main.c"
)

target_link_libraries(Termily PRIVATE winmm)


import pygame, sys

pygame.init()
pygame.mixer.init()


def main():
    clock = pygame.time.Clock()

    # window
    pygame.display.set_caption("Tytul naszego okienka")
    icon = pygame.image.load(r"./assets/icon.png")
    pygame.display.set_icon(icon)

    size = width, height = 800, 600
    screen = pygame.display.set_mode(size)

    # music
    pygame.mixer.music.load(r"./assets/sound/music.mp3")
    pygame.mixer.music.play(-1)

    # load moon
    moon = pygame.image.load(r"./assets/moon.jpg")
    moon = pygame.transform.scale(moon, size)

    surf_center = ((width - moon.get_width()) / 2, (height - moon.get_height()) / 2)
    screen.blit(moon, surf_center)

    # load ball
    ball = pygame.image.load(r"./assets/ball.gif")
    ball = pygame.transform.scale(ball, (50, 50))
    screen.blit(
        ball,
        (width / 2, height / 2),
    )

    ballrect = ball.get_rect(center=(width / 2, height / 2))
    pygame.display.flip()

    speed = [0, 0]
    acceleration = [0.1, 0.1]

    while True:
        clock.tick(60)
        pygame.time.delay(50)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

        keys = pygame.key.get_pressed()
        if keys[pygame.K_ESCAPE]:
            sys.exit()

        # move ball
        if keys[pygame.K_UP]:
            pass
        elif keys[pygame.K_DOWN]:
            pass
        elif keys[pygame.K_LEFT]:
            pass
        elif keys[pygame.K_RIGHT]:
            pass

        ballrect = ballrect.move(speed)
        if ballrect.left < 0 or ballrect.right > width:
            speed[0] = -speed[0]
        if ballrect.top < 0 or ballrect.bottom > height:
            speed[1] = -speed[1]

        screen.blit(moon, surf_center)
        screen.blit(ball, ballrect)
        pygame.display.flip()


if __name__ == "__main__":
    main()
    pygame.quit()
    sys.exit()

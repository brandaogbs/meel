import random

import pygame


# definicao da resolucao
DISPLAY_WIDTH  = 800
DISPLAY_HEIGHT = 1000

# definicao das cores (monokai)
gray   = (39,40,34)
white  = (255,255,255)
orange = (253,151,31)
pink   = (249,38,114)
blue   = (102,217,239)
green  = (166,226,46)

# cor dos blocos
blockColors = [orange, pink, blue, green]



###############################################################################
#                                 Constantes
###############################################################################
# definicoes gerais
gameDisplay = pygame.display.set_mode((DISPLAY_WIDTH, DISPLAY_HEIGHT))
pygame.display.set_caption("Projeto Integrado 1B!")
clock = pygame.time.Clock()

# load da imagem do carro
carImg = pygame.image.load('figs/mario.png')

# pega uma cor aleatoria da lista
def random_color():
    return random.choice(blockColors)

###############################################################################
#                                 Texto
###############################################################################
# renderiza o texto
def text_objects(text, font, color):
    textSurface = font.render(text, True, color)
    return textSurface, textSurface.get_rect()

# apresenta texto na tela
def display_message(text, color):
    largeText = pygame.font.Font('freesansbold.ttf', 115)
    
    TextSurf, TextRect = text_objects(text, largeText, color)
    TextRect.center = (DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2)

    gameDisplay.blit(TextSurf, TextRect)
    pygame.display.update()
    


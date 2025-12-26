import pygame

TAMANHO_CELULA = 64
SPRITES = None
FONTE = None


def init_font():
    global FONTE
    FONTE = pygame.font.SysFont("consolas", 22)


def init_sprites():
    global SPRITES
    SPRITES = pygame.image.load("sprites.png").convert_alpha()


class Tropa:
    def __init__(self, tipo):
        self.clas = tipo
        self.pos = (0, 0)
        self.idmapa = None  # ID no grid

        # --- ESTATÍSTICAS (voltou!) ---
        if tipo == "g":       # Guerreiro
            self.atac = 2
            self.defe = 4
            self.alca = 1
            self.desl = 2
            self.maxhp = 40
            self.sprite_y = 0

        elif tipo == "a":     # Arqueiro
            self.atac = 3
            self.defe = 2
            self.alca = 4
            self.desl = 3
            self.maxhp = 20
            self.sprite_y = 64

        elif tipo == "m":     # Mago
            self.atac = 5
            self.defe = 1
            self.alca = 3
            self.desl = 2
            self.maxhp = 20
            self.sprite_y = 128

        # Vida inicial
        self.hp = self.maxhp

    def desenhar(self, tela):
        x, y = self.pos
        px = x * TAMANHO_CELULA
        py = y * TAMANHO_CELULA

        # Sprite
        rect = pygame.Rect(0, self.sprite_y, 64, 64)
        tela.blit(SPRITES, (px, py), rect)

        # Texto: HP acima da cabeça
        if FONTE:
            vida = FONTE.render(str(self.hp), True, (255, 255, 255))
            tela.blit(vida, (px + 18, py - 4))

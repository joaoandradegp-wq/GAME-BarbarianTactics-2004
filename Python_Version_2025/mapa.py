import pygame

TAMANHO_CELULA = 64

class Mapa:
    def __init__(self):
        self.grid = [[0 for _ in range(7)] for _ in range(7)]
        self.area_mov = [[0 for _ in range(7)] for _ in range(7)]
        self.area_atk = [[0 for _ in range(7)] for _ in range(7)]

    def reset_areas(self):
        for y in range(7):
            for x in range(7):
                self.area_mov[y][x] = 0
                self.area_atk[y][x] = 0

    def colocar(self, x, y, valor):
        self.grid[y][x] = valor

    def limpar(self, x, y):
        self.grid[y][x] = 0

    def obter(self, x, y):
        return self.grid[y][x]

    def dentro_do_mapa(self, x, y):
        return 0 <= x < 7 and 0 <= y < 7

    # --- ÁREA DE MOVIMENTO (idêntica ao C++) --- #
    def calc_area_mov(self, x, y, alcance):
        b = 0
        d = -alcance - 1

        for a in range(y - alcance, y + alcance + 1):
            d += 1
            b += 1 if d <= 0 else -1

            for c in range(x - b + 1, x + b):
                if self.dentro_do_mapa(c, a):
                    if self.grid[a][c] == 0:
                        self.area_mov[a][c] = 1

    # --- ÁREA DE ATAQUE (igual ao C++) --- #
    def calc_area_atk(self, x, y, alcance):
        b = 0
        d = -alcance - 1

        for a in range(y - alcance, y + alcance + 1):
            d += 1
            b += 1 if d <= 0 else -1

            for c in range(x - b + 1, x + b):
                if self.dentro_do_mapa(c, a):
                    self.area_atk[a][c] = 1

    # --- DESENHO --- #
    def desenhar(self, tela):
        for y in range(7):
            for x in range(7):
                px = x * TAMANHO_CELULA
                py = y * TAMANHO_CELULA

                pygame.draw.rect(tela, (80, 80, 80), (px, py, TAMANHO_CELULA, TAMANHO_CELULA))
                pygame.draw.rect(tela, (200, 200, 200), (px, py, TAMANHO_CELULA, TAMANHO_CELULA), 1)

                if self.area_mov[y][x]:
                    pygame.draw.rect(tela, (80,160,255), (px+6, py+6, 52, 52))

                if self.area_atk[y][x]:
                    pygame.draw.rect(tela, (255,60,60), (px+6, py+6, 52, 52))

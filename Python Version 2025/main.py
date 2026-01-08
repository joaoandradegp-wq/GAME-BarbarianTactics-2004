import pygame
import sys
from mapa import Mapa
from classes import Tropa, init_font, init_sprites

pygame.init()

# --- CRIA A JANELA PRIMEIRO! ---
LARGURA = 640
ALTURA = 480
TELA = pygame.display.set_mode((LARGURA, ALTURA))
pygame.display.set_caption("Barbarian Tactics - Python Remake")

# Agora sim pode carregar fontes e sprites
init_font()
init_sprites()

FONTE = pygame.font.SysFont("consolas", 20)
TAMANHO_CELULA = 64


def desenhar_texto(surface, texto, x, y, cor=(255,255,255)):
    img = FONTE.render(texto, True, cor)
    surface.blit(img, (x, y))


def main():
    clock = pygame.time.Clock()
    mapa = Mapa()

    jogador = [
        [Tropa('g'), Tropa('a'), Tropa('m'), Tropa('g'), Tropa('a')],
        [Tropa('m'), Tropa('g'), Tropa('a'), Tropa('m'), Tropa('g')]
    ]

    for i in range(5):
        jogador[0][i].idmapa = i + 1
        jogador[1][i].idmapa = i + 6

        jogador[0][i].pos = (i+1, 0)
        jogador[1][i].pos = (i+1, 6)

        mapa.colocar(i+1, 0, jogador[0][i].idmapa)
        mapa.colocar(i+1, 6, jogador[1][i].idmapa)

    vez = 0
    selecionado = None

    while True:
        clock.tick(30)

        for evento in pygame.event.get():
            if evento.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            if evento.type == pygame.MOUSEBUTTONDOWN:
                mx, my = pygame.mouse.get_pos()
                cx = mx // TAMANHO_CELULA
                cy = my // TAMANHO_CELULA

                conteudo = mapa.obter(cx, cy)

                if conteudo != 0:
                    jogador_id = 0 if conteudo <= 5 else 1
                    tropa_id = conteudo - 1 if jogador_id == 0 else conteudo - 6

                    if jogador_id == vez:
                        tropa = jogador[jogador_id][tropa_id]
                        selecionado = (tropa, tropa_id, cx, cy)

                        mapa.reset_areas()
                        mapa.calc_area_mov(cx, cy, tropa.desl)
                        mapa.calc_area_atk(cx, cy, tropa.alca)

                    else:
                        if selecionado and mapa.area_atk[cy][cx]:
                            atacante = selecionado[0]
                            defensor = jogador[jogador_id][tropa_id]

                            dano = max(1, atacante.atac * 3 - defensor.defe)
                            defensor.hp -= dano

                            if defensor.hp <= 0:
                                mapa.limpar(cx, cy)

                            mapa.reset_areas()
                            selecionado = None
                            vez = 1 - vez

                else:
                    if selecionado and mapa.area_mov[cy][cx]:
                        tropa, t_id, ox, oy = selecionado

                        mapa.limpar(ox, oy)
                        tropa.pos = (cx, cy)
                        mapa.colocar(cx, cy, tropa.idmapa)

                        mapa.reset_areas()
                        selecionado = None
                        vez = 1 - vez

        TELA.fill((0, 0, 0))
        mapa.desenhar(TELA)

        for j in range(2):
            for i in range(5):
                if jogador[j][i].hp > 0:
                    jogador[j][i].desenhar(TELA)

        desenhar_texto(TELA, f"Vez do Jogador {vez+1}", 450, 20)

        pygame.display.update()


if __name__ == "__main__":
    main()

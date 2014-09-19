TARGET=planocomplejo
OUTDIR=../imagenes/

all: pdf clean move

pdf:
	@echo "==============================================="
	@echo "Compilando con python, el archivo:" $(TARGET)
	@python $(TARGET).py

clean:
	@echo "==============================================="
	@echo "Quitando archivos irrelevantes."
	@rm -rf *.pyc

move:
	@echo "==============================================="
	@echo "Moviendo el archivo a la carpeta de imagenes."
	@mv "$(TARGET).pdf" "$(OUTDIR)$(TARGET).pdf"

TARGET=teoriadecontrol
OUTDIR=./PDF's/
.PHONY: all completebook completeebook book ebook movebook moveebook clean

all: completebook completeebook clean

completebook: book movebook

completeebook: ebook moveebook

book:
	@${MAKE} clean
	@echo "==============================================="
	@echo "Compilando con pdflatex, el archivo:" $(TARGET)
	@pdflatex -interaction=batchmode "\newif\ifebook\ebookfalse\input{$(TARGET).tex}" || cat $(TARGET).log | grep -A1 "!"
	@pdflatex -interaction=batchmode "\newif\ifebook\ebookfalse\input{$(TARGET).tex}"
	@pdflatex -interaction=batchmode "\newif\ifebook\ebookfalse\input{$(TARGET).tex}"

ebook:
	@${MAKE} clean
	@echo "==============================================="
	@echo "Compilando con pdflatex, el archivo:" $(TARGET)
	@pdflatex -interaction=batchmode "\newif\ifebook\ebooktrue\input{$(TARGET).tex}"
	@pdflatex -interaction=batchmode "\newif\ifebook\ebooktrue\input{$(TARGET).tex}"
	@pdflatex -interaction=batchmode "\newif\ifebook\ebooktrue\input{$(TARGET).tex}"

movebook:
	@echo "==============================================="
	@echo "Moviendo el archivo a la carpeta de PDF's."
	@mv "$(TARGET).pdf" "$(OUTDIR)$(TARGET).pdf"

moveebook:
	@echo "==============================================="
	@echo "Moviendo el archivo a la carpeta de PDF's."
	@mv "$(TARGET).pdf" "$(OUTDIR)$(TARGET)-ebook.pdf"

clean:
	@echo "==============================================="
	@echo "Quitando archivos irrelevantes."
	@rm -rf *.aux *.log *.fdb_latexmk *.synctex.gz *.out *.tdo *.toc

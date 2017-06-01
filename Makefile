#####################################################
# 1 test for PRDUCT_COPY_FILE
# 2 test for basic func  foreach,eval,word,subst,info,filter
# 3 how to indicate space
######################################################

PRODUCT_COPY_FILES:=a:out/a

nullstring:= 
space :=$(nullstring) #end of the line


PRODUCT_COPY_FILES+=a:out/a


PRODUCT_COPY_FILES+=b:out/a
PRODUCT_COPY_FILES+=c:out/c

$(info #0#########copyfile end $(PRODUCT_COPY_FILES))



unique_product_copy_files_pairs :=
$(foreach cf,$(PRODUCT_COPY_FILES), \
	$(if $(filter $(unique_product_copy_files_pairs),$(cf)),,\
		$(eval unique_product_copy_files_pairs += $(cf))))


$(info #1#########copyfile end $(unique_product_copy_files_pairs))
################################################
##  func word-colon
###############################################
define word-colon
$(word $(1),$(subst :,$(space),$(2)))
endef

unique_product_copy_files_destinations	:=
$(foreach cf,$(unique_product_copy_files_pairs),	\
	$(info ++++++++++++$(cf) $(subst :,$(space),$(cf)) ++++)	\
	$(eval _src	:=$(call word-colon,1,$(cf)))	\
	$(eval _dest	:=$(call word-colon,2,$(cf)))	\
	$(info ++++++++++++$(_src)++++$(_dest)++++)	\
	$(if $(filter $(unique_product_copy_files_destinations),$(_dest)),\
		$(info PRODUCT_COPY_FILES $(cf) ignored.),\
		$(eval unique_product_copy_files_destinations+=$(_dest))))


$(info #2#########copyfile end $(unique_product_copy_files_destinations))



define func
foo:
	@echo "at foo"
endef

all:	foo main
	@echo "final"

$(eval $(call func,foo,abc.c))

main:   main.o Joseph_ring.o
	gcc -o main_new main.o Joseph_ring.o

main.o: main.c Joseph_ring.h
	gcc -c main.c

Joseph_ring.o:  Joseph_ring.c Joseph_ring.h
	gcc -c Joseph_ring.c
clean:  
	rm -f *.o main_new


.PHONY: clean All

All:
	@echo "----------Building project:[ cda - Debug ]----------"
	@$(MAKE) -f  "cda.mk"
clean:
	@echo "----------Cleaning project:[ cda - Debug ]----------"
	@$(MAKE) -f  "cda.mk" clean

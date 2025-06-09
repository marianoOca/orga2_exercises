
;########### LISTA DE FUNCIONES IMPORTADAS
extern save_result

;########### SECCION DE DATOS
section .data

filename_5: db 'results_5',0
filename_9: db 'results_9',0

;########### SECCION DE TEXTO (PROGRAMA)
section .text

;########### LISTA DE FUNCIONES EXPORTADAS
global alternate_sum_5
global alternate_sum_9

;########### DEFINICION DE FUNCIONES
; la funcion debe devolver el resultado de x1 - x2 + x3 - x4 + x5
; uint32_t alternate_sum_5(uint32_t x1, uint32_t x2, uint32_t x3, uint32_t x4, uint32_t x5);
; registros: x1[ebp+0x08], x2[ebp+0x0C], x3[ebp+0x10], x4[ebp+0x14], x5[ebp+0x18]
alternate_sum_5:
	;prologo
	push ebp	
	mov ebp, esp
	push ebx	
	push esi
	push edi	

	xor eax, eax	; limpiamos eax
	add eax, [ebp+0x08]	; realizamos las sumas alternadas
	sub eax, [ebp+0x0C]

	add eax, [ebp+0x10]
	sub eax, [ebp+0x14]
	add eax, [ebp+0x18]	


	mov ebx, eax	
	push eax
	push filename_5
	call save_result
	add esp, 8
	mov eax, ebx

	;epilogo
	pop edi
	pop esi
	pop ebx
	pop ebp
	
	ret		; cambio iret por ret


	
; la funcion debe devolver el resultado de x1 - x2 + x3 - x4 + x5 - x6 + x7 - x8 + x9
; uint32_t alternate_sum_9(uint32_t x1, uint32_t x2, uint32_t x3, uint32_t x4, uint32_t x5, uint32_t x6, uint32_t x7, uint32_t x8, uint32_t x9);	
; registros: x1[ebp+0x08], x2[ebp+0x0C], x3[ebp+0x10], x4[ebp+0x14], x5[ebp+0x18], x6[ebp+0x1C], x7[ebp+0x20], x8[ebp+0x24], x9[ebp+0x28]
alternate_sum_9:
	;prologue
	push ebp	
	mov ebp, esp
	push ebx	
	push esi	
	push edi	


	xor eax, eax	; limpiamos eax
	add eax, [ebp + 0x08]	; sumamos todos los elementos
	sub eax, [ebp + 0x0C]
	add eax, [ebp + 0x10]
	sub eax, [ebp + 0x14]
	add eax, [ebp + 0x18]
	sub eax, [ebp + 0x1C]
	add eax, [ebp + 0x20]
	sub eax, [ebp + 0x24]
	add eax, [ebp + 0x28]	; lo agrego yo

	mov ebx, eax	
	push eax
	push filename_9
	call save_result
	add esp, 8
	mov eax, ebx

	;epilogue
	pop edi
	pop esi
	pop ebx
	pop ebp	
	
	ret
	

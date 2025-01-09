.thumb
.align 2
.section pityFuncHook
hook_080684EC:
	bl pityHookStart
	b itemCheck

	# itemCheck is 0x0806852C

.section PityMod 
# starts at 0x08650AEC

pityHookStart:
	push {r14}
	
	# r8 contains id of enemy...
	mov r0, r8
	bl pityCoreStart
	# C function, will return an int in r0

	cmp r4, r5
	bcc pityHookEnd
	mov r0, #0x2

pityHookEnd:
	pop {r2}
	add r2, r2, r0
	# r0 should always either be 0 or 0x3C
	bx r2 


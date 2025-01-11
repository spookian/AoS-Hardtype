.thumb

.align 2
.section pityFuncHook, "awx"
hook_080684EC:
	ldr r3, =pityHookStart_arm
	bx r3

	# itemCheck is 0x0806852C

.section pityHack, "awx"
# starts at 0x08650AEC

.arm
pityHookStart_arm:
	# bit 1 should be 1 to switch to thumb
	add r3, r3, #0x9
	bx r3

.thumb
pityHookStart_thumb:
	add r4, r0, #0
	cmp r4, r5
	bcs pityHookExecute
	mov r0, r8
	bl pityCoreDisable
	mov r0, #0x8
	b pityHookEnd

pityHookExecute:
	# r8 contains id of enemy...
	mov r0, r8
	bl pityCoreStart
	# C function, will return an int in r0

pityHookEnd:
	ldr r1, =(hook_080684EC + 0x1)
	add r1, r0, r1

	ldrb r2, [r6, #0x17]
	# r0 should always either be 0 or 0x3C
	bx r1


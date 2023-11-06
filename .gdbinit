define child
	disp argv[1]
	disp argv[2]
	disp fd
end


define openf
	disp file
	disp in_out
	disp status
end

define exec
	disp *pype->path
	disp *pype->path[pype.pos]
	disp *cmd_n_flags@5
	disp pype->access
end

define get_p
	disp index
	disp words
	disp envp[index]
	disp path[index]
end

define	p_child
	set follow-fork-mode child
end

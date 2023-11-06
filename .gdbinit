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
	disp pype->path
	disp pype
	disp cmd_n_flags
end

define get_p
	disp index
	disp words
	disp envp[index]
	disp path[index]

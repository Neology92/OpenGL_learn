    #shader vertex
	#version 330 core
	
	layout(location = 0) in vec3 pos;
	
	void main()
	{
		gl_Position = vec4(pos.x, pos.y, pos.z, 1.0f);
	};

    #shader fragment
   	#version 330 core
	
	out vec4 color;
	
	void main()
	{
		color = vec4(1.0, 0.0, 0.0, 1.0f);
	};
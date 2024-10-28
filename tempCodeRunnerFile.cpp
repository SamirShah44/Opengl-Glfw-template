for (unsigned int i = 0; i < 10; i++)
		// {
		// 	glm::mat4 model = glm::mat4(1.0f);
		// 	model = glm::translate(model, cubePositions[i]);
		// 	float angle = 20.0f * i;
		// 	model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		// 	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, &model[0][0]);

		// 	glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
		// }